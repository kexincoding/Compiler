%{
#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "y.tab.h"
int line=0;
int yywrap(void);
%}

%x COMMENT
%x CMNT

%%
"/*" { BEGIN COMMENT; }
<COMMENT>. |
<COMMENT>\n ;
<COMMENT>"*/" {BEGIN INITIAL; }


"//" { BEGIN CMNT; }
<CMNT>\n {BEGIN INITIAL; }



[ \t]	{;}
[\n]	{line++;}
"begin"	{return SYM_begin;}
"end"	{return SYM_end;}
"if"	{return SYM_if;}
"else"	{return SYM_else;}
"int"	{return SYM_int;}
"array"	{return SYM_array;}
"bool"	{return SYM_bool;}
"while"	{return SYM_while;}
"write"	{return SYM_write;}
"read"	{return SYM_read;}

"call"	{return SYM_call;}
"const"	{return SYM_const;}
"do"	{return SYM_do;}
"odd"	{return SYM_odd;}
"procedure"	{return SYM_procedure;}
"then"	{return SYM_then;}
"var"	{return SYM_var;}
"true"	{return SYM_true;}
"false"	{return SYM_false;}
"XOR"	{return SYM_xor;}
"ODD"	{return SYM_odd;}
"exit"	{return SYM_exit;}
"repeat" {return SYM_repeat;}
"until"	{return SYM_until;}
"break"	{return SYM_break;}
"continue"	{return SYM_continue;}
"for"	{return SYM_for;}
"function" {return SYM_function;}
"declare"	{return SYM_declare;}
"return"	{return SYM_return;}
"case"		{return SYM_case;}
"when"		{return SYM_when;}



[A-Za-z]([A-Za-z]|[0-9])*	{
	yylval.ident=(char *)malloc(strlen(yytext)+1);
	strcpy(yylval.ident,yytext);
	return SYM_ident;
}

[0-9]+	{
	yylval.number=atoi(yytext);
	return SYM_number;}

":="		{return SYM_becomes;}
"<"		{return SYM_lss;}
"<="	{return SYM_leq;}
">"		{return SYM_gtr;}
">="	{return SYM_geq;}
"+"		{return SYM_plus;}
"-"		{return SYM_minus;}
"*"		{return SYM_times;}
"/"		{return	SYM_slash;}
"("		{return	SYM_lparen;}
")"		{return	SYM_rparen;}
","		{return SYM_comma;}
"."		{return SYM_period;}
"!="	{return SYM_neq;}
"=="	{return	SYM_eql;}
";"		{return	SYM_semicolon;}
"!"		{return SYM_not;}
"||"	{return SYM_or;}
"&&"	{return SYM_and;}
"^"	{return SYM_xor;}
"%"	{return SYM_mod;}
"++"	{return SYM_dplus;}
"--"	{return SYM_dminus;}
"["		{return SYM_lps;}
"]"		{return SYM_rps;}
"@"		{return SYM_abs;}
":"		{return SYM_colon;}
.		{yyerror("unknown character");}


%%

void redirectInput(FILE *input){
	yyin=input;
	return;
}

int yygetchar(void){
	int ret;
	ret=getc(yyin);
	printf("%c",ret);
	return ret;
}

int yywrap(void)
{
return 1;
}
