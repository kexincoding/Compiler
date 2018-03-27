////////////////////////////////////////////////////////
//声明部分
%{
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<memory.h>
#include<string.h>

#define bool int
#define true 1
#define false 0

#define txmax 100     /* 符号表容量 */
#define al 10         /* 标识符的最大长度 */
#define amax 2048     /* 地址上界*/
#define levmax 3      /* 最大允许过程嵌套声明层数*/
#define cxmax 200     /* 最多的虚拟机代码数 */
#define stacksize 500 /* 运行时数据栈元素最多为500个 */

/* 符号表中的类型 */
enum object {
    constant, 
    variable, 
    procedure,
    booltype,
    array,
};

/* 符号表结构 */
struct tablestruct
{
   char name[al];      /* 名字 */
   enum object kind;   /* 类型：const，var或procedure */
   int val;            /* 数值，仅const使用 */
	 int level;          /* 所处层，仅const不使用 */ 
	 int adr;            /* 地址，仅const不使用 */
	 int size;           /* 需要分配的数据区空间, 仅procedure使用 */
};
struct tablestruct table[txmax]; /* 符号表 */

/* 虚拟机代码指令 */
enum fct {
    lit,     opr,     lod, 
    sto,     cal,     ini, 
    jmp,     jpc,     ext,
    lodc,
};

/* 虚拟机代码结构 */
struct instruction
{
	enum fct f;   /* 虚拟机代码指令 */
	int l;        /* 引用层与声明层的层次差 */
	int a;        /* 根据f的不同而不同 */
};
struct instruction code[cxmax]; /* 存放虚拟机代码的数组 */

int pp;
int rr;
int ff;
int link;
int add;
int flag1;
int flag2;
int tx;         /* 符号表当前尾指针 */
int cx;         /* 虚拟机代码指针, 取值范围[0, cxmax-1] */
int px;         /* 嵌套过程索引表proctable的指针 */
int lev;        /* 层次记录 */
int proctable[3];   /* 嵌套过程索引表，最多嵌套三层 */
char id[al];
int num;
bool listswitch;   /* 显示虚拟机代码与否 */
bool tableswitch;  /* 显示符号表与否 */

FILE* fin;      /* 输入源文件 */
FILE* ftable;	  /* 输出符号表 */
FILE* fcode;    /* 输出虚拟机代码 */
FILE* foutput;  /* 输出出错示意（如有错） */
FILE* fresult;  /* 输出执行结果 */
char fname[al];
int err;
extern int line; 

void init();
int enter(enum object k);
int position(char *s);
void setdx(int n);
void gen(enum fct x, int y, int z);
void listall();
void displaytable();
void interpret();
int base(int l, int* s, int b);
%}

////////////////////////////////////////////////////////
//辅助定义部分
%union{
char *ident;
int number;
}

%token SYM_begin SYM_call SYM_const
%token SYM_do SYM_end SYM_if SYM_else
%token SYM_procedure
%token SYM_then SYM_var SYM_while SYM_until
%token SYM_read SYM_write



%token SYM_comma SYM_becomes
%token SYM_period SYM_semicolon

%token SYM_eql SYM_neq SYM_lss SYM_leq SYM_gtr SYM_geq
%token SYM_plus SYM_minus
%token SYM_times SYM_slash
%token SYM_abs
%token SYM_lparen SYM_rparen

%token SYM_not SYM_or SYM_and
%token SYM_int SYM_bool

%token SYM_mod SYM_xor SYM_odd SYM_dplus SYM_dminus
%token SYM_exit SYM_repeat SYM_util SYM_break SYM_continue SYM_for
%token SYM_lps SYM_rps SYM_array
%token SYM_lbr SYM_rbr
%token SYM_function
%token SYM_declare
%token SYM_return
%token SYM_case SYM_when SYM_colon


%left SYM_or SYM_xor
%left SYM_and
%left SYM_neq SYM_eql
%left SYM_gtr SYM_geq SYM_lss SYM_leq
%left SYM_plus SYM_minus
%left SYM_times SYM_slash SYM_mod
%left SYM_dplus SYM_dminus
%right SYM_not SYM_odd
%left SYM_lps SYM_rps
%nonassoc SYM_abs	
%nonassoc SYM_lparen SYM_rparen 

%nonassoc LOWER_THAN_ELSE
%nonassoc SYM_else
%nonassoc LOW_EXP


%token <ident> SYM_ident
%token <number> SYM_number
%token <number> SYM_true
%token <number> SYM_false


%%

program:
		{
			gen(jmp, 0, 1); 
		}
		procedurelist
	;

procedurelist:		pro
		|	procedurelist pro
		;

pro:		SYM_procedure SYM_ident 
		{                 
		       strcpy(id, $2); 
	               add = cx;  
		       enter(procedure); 
		}
		stmt_sequence
		{
			ff=cx;
			gen(jmp, 0, cx+1); 
		}
	;



stmt_sequence:
		statement SYM_semicolon
	|	stmt_sequence  statement SYM_semicolon
	;

statement:
		assign_stmt	
	|	if_stmt
	|	repeat_stmt
	|	read_stmt
	|	write_stmt
	|	whiledo_stmt
	|	dowhile_stmt
	|	for_stmt
	|	break_stmt
	|	con_stmt
	|	exit_stmt
	|	define_stmt
	|	array_stmt
	|	call_stmt
	|	case_stmt
	|	return_stmt
	|	exp;
	;



call_stmt: SYM_call SYM_ident
             {
		int i=0;
		
		strcpy(id,$2);
		i=position(id);
                 if (i == 0)
                       yyerror("call Symbol does not exist");
                 else
                    {
                       if (table[i].kind != procedure)
                           yyerror("Symbol should be a procedure");
                       else
		       {
                           gen (cal, 0, table[i].adr);    
			   code[ff].a=cx;
			 }
		
                    }
              }
          ;

case_stmt:
		SYM_case SYM_colon when_then_seq SYM_else stmt_sequence SYM_end
		{
			int x=0;
			while(link!=0){
				x=code[link].a;
				code[link].a=cx;
				link=x;
			}
			link=0;
		}
	;

when_then_seq:
		when_then
	|	when_then_seq when_then
	;

when_then:
		SYM_when condition SYM_then stmt_sequence
		{
			gen(jmp,0,link);
			link=cx-1;
			code[$<number>2].a=cx;
		}
	;


array_stmt:
		SYM_ident
		SYM_lps
		exp
		SYM_rps
		SYM_becomes 
		exp
		{
			int i;
			strcpy(id,$1);
			i=position(id);
			if(i==0){
				yyerror("not exist!");
			}
			else{
				if(table[i].kind!=array){
					yyerror("not array!");
					i=0;
				}
			}
			if(i!=0){
				gen(sto,0,table[i].adr);
			}
		}
	;

break_stmt:
		SYM_break
		{	
			flag1=cx;
			gen(jmp,0,0);
		}
	;

con_stmt:
		SYM_continue 
		{
			flag2=cx;
			gen(jmp,0,0);
		}
	;


exit_stmt:
		SYM_exit 
		{
			gen(ext,0,0);
		}
	;


whiledo_stmt:
		SYM_while 
		{
			$<number>$=cx;
		}
		condition SYM_do  SYM_begin
		stmt_sequence SYM_end
		{			
			gen(jmp,0,$<number>2);
			code[$<number>3].a=cx;
			if(flag1!=-1)
				code[flag1].a=cx;
			if(flag2!=-1)
				code[flag2].a=$<number>2;
		}
	
dowhile_stmt:
		SYM_do 
		{
			$<number>$=cx;
		}
		stmt_sequence SYM_begin
		SYM_while 
		{
			$<number>$=cx;
		}
		condition SYM_end 
		{
		        gen(jmp,0,$<number>2);
			code[$<number>7].a=cx;
			if(flag1!=-1)
				code[flag1].a=cx;
			if(flag2!=-1)
				code[flag2].a=$<number>6;
		}
	;
for_stmt:
		SYM_for SYM_lparen assign_stmt 
		{
			$<number>$=cx;
		}
		exp 
		{
			$<number>$=cx;
			gen(jpc,0,0);
			gen(jmp,0,0);
		}
		assign_stmt 
		{
			gen(jmp,0,$<number>4);			
			code[$<number>6+1].a=cx;
		}
		SYM_rparen stmt_sequence SYM_end
		{
			gen(jmp,0,$<number>6+2);
			code[$<number>6].a=cx;
			if(flag1!=-1)
				code[flag1].a=cx;
			if(flag2!=-1)
				code[flag2].a=$<number>4;
		}
	;

assign_stmt:
		SYM_ident SYM_becomes exp
		{
			int i=0,a=0,b=0;
			strcpy(id,$1);
			a=ifconst(id);	
			i=position(id);
			if(a==1)
			{
			   yyerror("constant number!");
			   break;
			}
			b=ifbooltype(id);
			printf( "$<number>3=%d\n", $<number>3);
			if(b==1 && ($<number>3!=1 && $<number>3!=0))
			{
			   yyerror("bool!");
			   break;
			}
			if(i==0){
				i=enter(variable);
			}
			if(i!=0){
				gen(sto,0,table[i].adr);
			}
		}
	;

define_stmt:	SYM_bool SYM_ident
		{
			int i=0;
			strcpy(id,$2);
			i=position(id);
			i=enter(booltype);


		}

		| SYM_array
		SYM_ident
		{
			strcpy(id,$2);
			enter(array);
		}
		SYM_lps
		SYM_number
		{	
			tx += $5;
		}
		SYM_rps

		| SYM_const SYM_ident SYM_becomes SYM_number
		{
			int i=0;
			strcpy(id,$2);
			i=position(id);
			num=$4;
			if(i==0){
				i=enter(constant);
			}
			if(i!=0){
				 yyerror("Already exist!");
				 break;
			}
		}
	;

if_stmt:
		SYM_if condition SYM_then stmt_sequence SYM_end %prec LOWER_THAN_ELSE
		{
			code[$<number>2].a=cx;
		}

    |	SYM_if condition SYM_then stmt_sequence
    	{
    		$<number>$=cx;
			code[$<number>2].a=cx+1;
			gen(jmp,0,0); 
    	}
    	SYM_else stmt_sequence SYM_end
    	{
    		code[$<number>5].a=cx;
    	}
    ;

repeat_stmt:
		SYM_repeat 
		{
			$<number>$=cx;
		}
		stmt_sequence SYM_until exp
		{
			gen(jpc,0,$<number>2);
		}
	;

read_stmt:
		SYM_read SYM_ident
		{
			int i;
			strcpy(id,$2);
			i=position(id);
			if(i==0)
			{
				i=enter(variable);
			}
			gen(opr,0,16);
			gen(sto,0,table[i].adr);
		}
	;

write_stmt:
		SYM_write exp
		{ 
			gen(opr,0,14);
			gen(opr,0,15);
		}
	;

return_stmt:
		SYM_return SYM_ident
		{		
			strcpy(id,$2);
			pp=position(id);
			if(pp==0)
				yyerror("not inent");
			//printf( "pp=%d\n", pp);
			else
			gen(opr, 0, 30);
		}	
	;

condition:
		exp
		{
			$<number>$=cx;
			gen(jpc, 0, 0);
		}
	;

exp:
		exp SYM_eql exp
		{ gen(opr,0,8); }
	|	exp SYM_neq exp 
		{ gen(opr,0,9); }
	|	exp SYM_lss exp
		{ gen(opr,0,10); }
	|	exp SYM_geq exp
		{ gen(opr,0,11); }
	|	exp SYM_gtr exp
		{ gen(opr,0,12); }
	|	exp SYM_leq exp
		{ gen(opr,0,13); }
	|	exp SYM_and exp
		{ gen(opr,0,18); }
	|	exp SYM_or exp
		{ gen(opr,0,19); }
	|	exp SYM_xor exp
		{ gen(opr,0,20); }
	|	SYM_not exp
		{ gen(opr,0,21); }
	|	SYM_odd exp 
		{ gen(opr,0,6); }
	|	simple_exp

	;

simple_exp:
	 	simple_exp SYM_plus term
	 	{ gen(opr, 0, 2); }
	|	simple_exp SYM_minus term
		{ gen(opr, 0, 3); }
	|	term
	;


term:
		term SYM_times factor
		{ gen(opr, 0, 4); }
	|	term SYM_slash factor
		{ gen(opr, 0, 5); }
	|	term SYM_mod factor
		{ gen(opr,0,17);}
	|	factor
	;


factor:
		SYM_lparen exp SYM_rparen
	|	SYM_number
		{
			int num;
			num=$1;
			if(num>2000000000){
				yyerror("too big int");
				num=0;
			}
			gen(lit, 0, $1);
		}
	|	SYM_ident
		{
			int i;
			strcpy(id,$1);
			i=position(id);
			if(i==0)
			{
				i=enter(variable);
			}
			gen(lod,0,i);
		}
	|	SYM_ident 
		SYM_lps
		exp
		SYM_rps
		{
			int i;
			strcpy(id,$1);
			i=position(id);
			if(i==0){
				yyerror("not exist!");
			}else{
				if(table[i].kind!=array){
					yyerror("not array!");
					i=0;
				}
			}
			if(i!=0){
				gen(lod,0,table[i].adr);
			}
		}
	|	SYM_lparen SYM_call SYM_ident SYM_rparen
		{
			gen(lodc, 0, 0);
		}
	|	SYM_ident  SYM_dplus
		{
			int i;
			strcpy(id,$1);
			i=position(id);
			if(i==0)
				yyerror("not define");
			else
				gen(lod,0,table[i].adr);
			gen(opr,0,22);	
			gen(sto,0,table[i].adr);
		}

	|	SYM_ident  SYM_dminus
		{
			int i;
			strcpy(id,$1);
			i=position(id);
			if(i==0)
				yyerror("not define");
			else
				gen(lod,0,table[i].adr);
			gen(opr,0,23);	
			gen(sto,0,table[i].adr);
		}
	;


////////////////////////////////////////////////////////
//程序部分
%%
int yyerror(char *s)
{
	err = err + 1;
  printf("%s in line %d\n", s, line);
	fprintf(foutput, "%s in line %d\n", s, line);
	return 0;
}

/* 初始化 */
void init()
{
	tx = 0;
	cx = 0;
	px = 0;  
  lev = 0;   
  proctable[0] = 0;
  num = 0;
  err = 0;
  flag1 =-1;
  flag2 =-1;
  add=-1;
  link=0;
	ff=0;
	rr=0;
	pp=-1;
}

/* 在符号表中加入一项 */
int  enter(enum object k)
{
	tx = tx + 1;
	strcpy(table[tx].name, id);
	table[tx].kind = k;
	switch (k)
	{
		case booltype:
			table[tx].adr=tx;
			break;
		case array:
			table[tx].adr=tx;
			break;
		case constant:	/* 常量 */			
			table[tx].val = num; /* 登记常数的值 */
			table[tx].adr=tx;
			break;
		case variable:	/* 变量 */
			table[tx].level = lev;	
			table[tx].adr=tx;
		
			break;
		case procedure:	/* 过程 */
			table[tx].level = lev;
			table[tx].adr = add;
			printf("addb:%d\n",add);
			break;
	}
	return tx;
}

/* 查找标识符在符号表中的位置 */
int position(char *s)
{
	int i;
	strcpy(table[0].name, s);
	i = tx;
	while(strcmp(table[i].name, s) != 0)
		i--;
	return i;
}


int ifconst(char *s)
{
	int i,a;
	strcpy(table[0].name, s);
	i = tx;
	a=0;
	printf("%d\n",a);
	while(strcmp(table[i].name, s) != 0)
		i--;
	printf("%d\n",i);
	if(i!=0 && table[i].kind==constant)
		a=1;
	printf("%d\n",a);
	return a;
}


int ifbooltype(char *s)
{
	int i,a;
	strcpy(table[0].name, s);
	i = tx;
	a=0;
	while(strcmp(table[i].name, s) != 0)
		i--;
	if(i!=0 && table[i].kind==booltype)
		a=1;
	return a;
}

/* 为本层变量分配相对地址，从3开始分配 */
void setdx(int n)
{
	int i;
	for(i = 1; i <= n; i++)
		table[tx - i + 1].adr = n - i + 3;
}

/* 生成虚拟机代码 */
void gen(enum fct x, int y, int z)
{
	if (cx >= cxmax)
	{
		printf("Program is too long!\n");	/* 生成的虚拟机代码程序过长 */
		exit(1);
	}
	code[cx].f = x;
	code[cx].l = y;
	code[cx].a = z;
	cx++;
}

/* 输出所有目标代码  */
void listall()
{
	int i;
	char name[][5]=
	{
		{"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"int"},{"jmp"},{"jpc"},{"ext"},{"lodc"},
	};
	if (listswitch)
	{
		for (i = 0; i < cx; i++)
		{
			printf("%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
			fprintf(fcode,"%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
			
		}
	}
}

/* 输出符号表 */
void displaytable()
{
	int i;
if (tableswitch)		/* 输出符号表 */
	{
	
	for (i = 1; i <= tx; i++)
		{
			switch (table[i].kind)
			{
				case constant:
					printf("    %d const %s ", i, table[i].name);
					printf("val=%d\n", table[i].val);
					fprintf(ftable, "    %d const %s ", i, table[i].name);
					fprintf(ftable, "val=%d\n", table[i].val);
					break;
				case variable:
					printf("    %d var   %s ", i, table[i].name);
					printf("lev=%d addr=%d\n", table[i].level, table[i].adr);
					fprintf(ftable, "    %d var   %s ", i, table[i].name);
					fprintf(ftable, "lev=%d addr=%d\n", table[i].level, table[i].adr);
					break;
				case procedure:
					printf("    %d proc  %s ", i, table[i].name);
					printf("lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
					fprintf(ftable,"    %d proc  %s ", i, table[i].name);
					fprintf(ftable,"lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
					break;
			}
		}
		printf("\n");
		fprintf(ftable, "\n");
	}

}

/* 解释程序 */
void interpret()
{
	int p = 0; /* 指令指针 */
	int b = 1; /* 指令基址 */
	int t = 0; /* 栈顶指针 */
	struct instruction i;	/* 存放当前指令 */
	int s[stacksize];	/* 栈 */

	printf("Start pl0\n");
	fprintf(fresult,"Start pl0\n");
	s[0] = 0; /* s[0]不用 */
	s[1] = 0; /* 主程序的三个联系单元均置为0 */
	s[2] = 0;
	s[3] = 0;
	do {
	    i = code[p];	/* 读当前指令 */
		p = p + 1;
		switch (i.f)
		{
			case lit:	/* 将常量a的值取到栈顶 */
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	/* 数学、逻辑运算 */
				switch (i.a)
				{
					case 0:  /* 函数调用结束后返回 */
						
						t = b - 1;
						p = s[t + 3];						
						b = s[t + 2];
						break;
					case 1: /* 栈顶元素取反 */
						s[t] = - s[t];
						break;
					case 2: /* 次栈顶项加上栈顶项，退两个栈元素，相加值进栈 */
						t = t - 1;
						s[t] = s[t] + s[t + 1];
						break;
					case 3:/* 次栈顶项减去栈顶项 */
						t = t - 1;
						s[t] = s[t] - s[t + 1];
						break;
					case 4:/* 次栈顶项乘以栈顶项 */
						t = t - 1;
						s[t] = s[t] * s[t + 1];
						break;
					case 5:/* 次栈顶项除以栈顶项 */
						t = t - 1;
						s[t] = s[t] / s[t + 1];
						break;
					case 6:/* 栈顶元素的奇偶判断 */
						s[t] = s[t] % 2;
						break;
					case 8:/* 次栈顶项与栈顶项是否相等 */
						t = t - 1;
						s[t] = (s[t] == s[t + 1]);
						break;
					case 9:/* 次栈顶项与栈顶项是否不等 */
						t = t - 1;
						s[t] = (s[t] != s[t + 1]);
						break;
					case 10:/* 次栈顶项是否小于栈顶项 */
						t = t - 1;
						s[t] = (s[t] < s[t + 1]);
						break;
					case 11:/* 次栈顶项是否大于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] >= s[t + 1]);
						break;
					case 12:/* 次栈顶项是否大于栈顶项 */
						t = t - 1;
						s[t] = (s[t] > s[t + 1]);
						break;
					case 13: /* 次栈顶项是否小于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] <= s[t + 1]);
						break;
					case 14:/* 栈顶值输出 */
						printf("%d", s[t]);
						fprintf(fresult, "%d", s[t]);
						t = t - 1;
						break;
					case 15:/* 输出换行符 */
						printf("\n");
						fprintf(fresult,"\n");
						break;
					case 16:/* 读入一个输入置于栈顶 */
						t = t + 1;
						printf("?");
						fprintf(fresult, "?");
						scanf("%d", &(s[t]));
						fprintf(fresult, "%d\n", s[t]);						
						break;
					case 17:     //mod
					        t=t-1;
						s[t]=s[t]%s[t+1];
						break;
					case 18:
                                                t = t - 1;
						if ((s[t]!=0)&&(s[t+1]!=0))s[t]=1;
						else s[t]=0;
						break;
					case 19:
						t = t - 1;
						if ((s[t]!=0)||(s[t+1]!=0))s[t]=1;
						else s[t]=0;
						break;
					case 20:		
						t = t - 1;
						s[t] = (s[t] ^ s[t + 1]);
					case 21:
						if(s[t]!=0)s[t]=0;
						else s[t] = 1;

					case 22:    //++
						s[t]=s[t]+1;
						break;
					case 23:    //--
						s[t]=s[t]-1;
						break;
					case 30:
						rr=table[pp].val;
						//printf( "rr=%d\n", rr);	
						//printf( "pp=%d\n", pp);	

				}
				break;
			case lod:	/* 取相对当前过程的数据基地址为a的内存的值到栈顶 */
				t = t + 1;
				s[t] = table[i.a].val;				
				break;
			case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
				table[i.a].val = s[t];
				t = t - 1;
				break;
			case cal:	/* 调用子过程 */
				s[t + 1] = 0;	/* 将父过程基地址入栈，即建立静态链 */
				s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
				s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
				b = t + 1;	/* 改变基地址指针值为新过程的基地址 */
				p = i.a;	/* 跳转 */
				break;
			case ini:	/* 在数据栈中为被调用的过程开辟a个单元的数据区 */
				t = t + i.a;	
				break;
			case jmp:	/* 直接跳转 */
				p = i.a;
				break;
			case jpc:	/* 条件跳转 */
				if (s[t] == 0) 
					p = i.a;
				t = t - 1;
				break;
			case ext:
				exit(0);
			case lodc:
				s[t]=rr;
			
		}
		
	} while (p<=cx && p != 0);
	printf("End pl0\n");
	fprintf(fresult,"End pl0\n");
}

/* 通过过程基址求上l层过程的基址 */
int base(int l, int* s, int b)
{
	int b1;
	b1 = b;
	while (l > 0)
	{
		b1 = s[b1];
		l--;
	}
	return b1;
}

int main(void)
{
	printf("Input SAMLL file?   ");
	scanf("%s", fname);		/* 输入文件名 */

	if ((fin = fopen(fname, "r")) == NULL)
	{
		printf("Can't open the input file!\n");
		exit(1);
	}	
	if ((foutput = fopen("foutput.txt", "w")) == NULL)
	{
		printf("Can't open the output file!\n");
		exit(1);
	}
	if ((ftable = fopen("ftable.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
	
	printf("List object codes?(Y/N)");	/* 是否输出虚拟机代码 */
	scanf("%s", fname);
	listswitch = (fname[0]=='y' || fname[0]=='Y');

	printf("List symbol table?(Y/N)");	/* 是否输出符号表 */
	scanf("%s", fname);
	tableswitch = (fname[0]=='y' || fname[0]=='Y');
	
	redirectInput(fin);		
	init();
  yyparse();
	if(err == 0)
	{
		printf("\n===Parsing success!===\n");
		fprintf(foutput, "\n===Parsing success!===\n");
		if ((fcode = fopen("fcode.txt", "w")) == NULL)
		{
			printf("Can't open fcode.txt file!\n");
			exit(1);
		}		

		if ((fresult = fopen("fresult.txt", "w")) == NULL)
		{
			printf("Can't open fresult.txt file!\n");
			exit(1);
		}
		
		listall();  /* 输出所有代码 */
		fclose(fcode);
		
		interpret();	/* 调用解释执行程序 */        	
		fclose(fresult);
	}
  else
	{
		printf("%d errors in SMALL program\n", err);
		fprintf(foutput, "%d errors in SMALL program\n", err);
		
	}
	
	fclose(ftable);
  fclose(foutput);
	fclose(fin);
	return 0;
}



