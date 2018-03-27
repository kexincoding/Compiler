
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "yacc.y"

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


/* Line 189 of yacc.c  */
#line 167 "yacc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SYM_begin = 258,
     SYM_call = 259,
     SYM_const = 260,
     SYM_do = 261,
     SYM_end = 262,
     SYM_if = 263,
     SYM_else = 264,
     SYM_procedure = 265,
     SYM_then = 266,
     SYM_var = 267,
     SYM_while = 268,
     SYM_until = 269,
     SYM_read = 270,
     SYM_write = 271,
     SYM_comma = 272,
     SYM_becomes = 273,
     SYM_period = 274,
     SYM_semicolon = 275,
     SYM_eql = 276,
     SYM_neq = 277,
     SYM_lss = 278,
     SYM_leq = 279,
     SYM_gtr = 280,
     SYM_geq = 281,
     SYM_plus = 282,
     SYM_minus = 283,
     SYM_times = 284,
     SYM_slash = 285,
     SYM_abs = 286,
     SYM_lparen = 287,
     SYM_rparen = 288,
     SYM_not = 289,
     SYM_or = 290,
     SYM_and = 291,
     SYM_int = 292,
     SYM_bool = 293,
     SYM_mod = 294,
     SYM_xor = 295,
     SYM_odd = 296,
     SYM_dplus = 297,
     SYM_dminus = 298,
     SYM_exit = 299,
     SYM_repeat = 300,
     SYM_util = 301,
     SYM_break = 302,
     SYM_continue = 303,
     SYM_for = 304,
     SYM_lps = 305,
     SYM_rps = 306,
     SYM_array = 307,
     SYM_lbr = 308,
     SYM_rbr = 309,
     SYM_function = 310,
     SYM_declare = 311,
     SYM_return = 312,
     SYM_case = 313,
     SYM_when = 314,
     SYM_colon = 315,
     LOWER_THAN_ELSE = 316,
     LOW_EXP = 317,
     SYM_ident = 318,
     SYM_number = 319,
     SYM_true = 320,
     SYM_false = 321
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 98 "yacc.y"

char *ident;
int number;



/* Line 214 of yacc.c  */
#line 276 "yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 288 "yacc.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   685

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    13,    18,    21,
      25,    27,    29,    31,    33,    35,    37,    39,    41,    43,
      45,    47,    49,    51,    53,    55,    57,    59,    62,    69,
      71,    74,    79,    86,    88,    90,    92,    93,   101,   102,
     103,   112,   113,   114,   115,   127,   131,   134,   135,   136,
     144,   149,   155,   156,   165,   166,   172,   175,   178,   181,
     183,   187,   191,   195,   199,   203,   207,   211,   215,   219,
     222,   225,   227,   231,   235,   237,   241,   245,   249,   251,
     255,   257,   259,   264,   269,   272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,    -1,    69,    70,    -1,    71,    -1,    70,
      71,    -1,    -1,    10,    63,    72,    73,    -1,    74,    20,
      -1,    73,    74,    20,    -1,    92,    -1,    96,    -1,    98,
      -1,   100,    -1,   101,    -1,    83,    -1,    85,    -1,    88,
      -1,    80,    -1,    81,    -1,    82,    -1,    93,    -1,    79,
      -1,    75,    -1,    76,    -1,   102,    -1,   104,    -1,     4,
      63,    -1,    58,    60,    77,     9,    73,     7,    -1,    78,
      -1,    77,    78,    -1,    59,   103,    11,    73,    -1,    63,
      50,   104,    51,    18,   104,    -1,    47,    -1,    48,    -1,
      44,    -1,    -1,    13,    84,   103,     6,     3,    73,     7,
      -1,    -1,    -1,     6,    86,    73,     3,    13,    87,   103,
       7,    -1,    -1,    -1,    -1,    49,    32,    92,    89,   104,
      90,    92,    91,    33,    73,     7,    -1,    63,    18,   104,
      -1,    38,    63,    -1,    -1,    -1,    52,    63,    94,    50,
      64,    95,    51,    -1,     5,    63,    18,    64,    -1,     8,
     103,    11,    73,     7,    -1,    -1,     8,   103,    11,    73,
      97,     9,    73,     7,    -1,    -1,    45,    99,    73,    14,
     104,    -1,    15,    63,    -1,    16,   104,    -1,    57,    63,
      -1,   104,    -1,   104,    21,   104,    -1,   104,    22,   104,
      -1,   104,    23,   104,    -1,   104,    26,   104,    -1,   104,
      25,   104,    -1,   104,    24,   104,    -1,   104,    36,   104,
      -1,   104,    35,   104,    -1,   104,    40,   104,    -1,    34,
     104,    -1,    41,   104,    -1,   105,    -1,   105,    27,   106,
      -1,   105,    28,   106,    -1,   106,    -1,   106,    29,   107,
      -1,   106,    30,   107,    -1,   106,    39,   107,    -1,   107,
      -1,    32,   104,    33,    -1,    64,    -1,    63,    -1,    63,
      50,   104,    51,    -1,    32,     4,    63,    33,    -1,    63,
      42,    -1,    63,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   159,   159,   159,   165,   166,   170,   169,   185,   186,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   211,   234,   247,
     248,   252,   262,   288,   296,   305,   314,   313,   330,   335,
     329,   350,   354,   360,   349,   376,   403,   415,   421,   413,
     426,   443,   449,   448,   462,   461,   472,   487,   495,   508,
     516,   518,   520,   522,   524,   526,   528,   530,   532,   534,
     536,   538,   543,   545,   547,   552,   554,   556,   558,   563,
     564,   574,   585,   605,   609,   622
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYM_begin", "SYM_call", "SYM_const",
  "SYM_do", "SYM_end", "SYM_if", "SYM_else", "SYM_procedure", "SYM_then",
  "SYM_var", "SYM_while", "SYM_until", "SYM_read", "SYM_write",
  "SYM_comma", "SYM_becomes", "SYM_period", "SYM_semicolon", "SYM_eql",
  "SYM_neq", "SYM_lss", "SYM_leq", "SYM_gtr", "SYM_geq", "SYM_plus",
  "SYM_minus", "SYM_times", "SYM_slash", "SYM_abs", "SYM_lparen",
  "SYM_rparen", "SYM_not", "SYM_or", "SYM_and", "SYM_int", "SYM_bool",
  "SYM_mod", "SYM_xor", "SYM_odd", "SYM_dplus", "SYM_dminus", "SYM_exit",
  "SYM_repeat", "SYM_util", "SYM_break", "SYM_continue", "SYM_for",
  "SYM_lps", "SYM_rps", "SYM_array", "SYM_lbr", "SYM_rbr", "SYM_function",
  "SYM_declare", "SYM_return", "SYM_case", "SYM_when", "SYM_colon",
  "LOWER_THAN_ELSE", "LOW_EXP", "SYM_ident", "SYM_number", "SYM_true",
  "SYM_false", "$accept", "program", "$@1", "procedurelist", "pro", "$@2",
  "stmt_sequence", "statement", "call_stmt", "case_stmt", "when_then_seq",
  "when_then", "array_stmt", "break_stmt", "con_stmt", "exit_stmt",
  "whiledo_stmt", "@3", "dowhile_stmt", "@4", "@5", "for_stmt", "@6", "@7",
  "$@8", "assign_stmt", "define_stmt", "$@9", "$@10", "if_stmt", "@11",
  "repeat_stmt", "@12", "read_stmt", "write_stmt", "return_stmt",
  "condition", "exp", "simple_exp", "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    69,    68,    70,    70,    72,    71,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    76,    77,
      77,    78,    79,    80,    81,    82,    84,    83,    86,    87,
      85,    89,    90,    91,    88,    92,    93,    94,    95,    93,
      93,    96,    97,    96,    99,    98,   100,   101,   102,   103,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   105,   105,   105,   106,   106,   106,   106,   107,
     107,   107,   107,   107,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     0,     4,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     6,     1,
       2,     4,     6,     1,     1,     1,     0,     7,     0,     0,
       8,     0,     0,     0,    11,     3,     2,     0,     0,     7,
       4,     5,     0,     8,     0,     5,     2,     2,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     1,     4,     4,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     4,     6,     5,     0,
       0,     0,    38,     0,    36,     0,     0,     0,     0,     0,
       0,    35,    54,    33,    34,     0,     0,     0,     0,    81,
      80,     7,     0,    23,    24,    22,    18,    19,    20,    15,
      16,    17,    10,    21,    11,    12,    13,    14,    25,    26,
      71,    74,    78,    27,     0,     0,    81,     0,    59,     0,
      56,    57,     0,     0,    69,    46,    70,     0,     0,    47,
      58,     0,     0,    84,    85,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,    41,     0,     0,     0,    29,    45,     0,     9,    60,
      61,    62,    65,    64,    63,    67,    66,    68,    72,    73,
      75,    76,    77,    50,     0,     0,    52,     0,    83,     0,
       0,     0,     0,     0,    30,    82,    39,    82,    51,     0,
       0,    55,    42,    48,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    28,    32,     0,     0,    37,    43,    49,
      40,    53,     0,     0,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     9,    31,    32,    33,    34,
     104,   105,    35,    36,    37,    38,    39,    59,    40,    55,
     147,    41,   130,   150,   162,    42,    43,   102,   151,    44,
     139,    45,    67,    46,    47,    48,    57,    49,    50,    51,
      52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
     -67,    13,     7,   -67,   -21,     7,   -67,   -67,   -67,   564,
     -15,    -6,   -67,   -23,   -67,    -3,   -23,    15,   -23,    12,
     -23,   -67,   -67,   -67,   -67,    42,    14,    17,    23,   -12,
     -67,   564,    65,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   645,
      -7,    22,   -67,   -67,    69,   564,   -27,    75,   645,   -23,
     -67,   645,    33,    89,   -67,   -67,   -67,   564,    34,   -67,
     -67,    39,   -23,   -67,   -67,   -23,    80,   -67,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -20,   -20,   -20,
     -20,   -20,    37,   137,   -23,   564,    96,    71,   -67,   198,
      87,   -67,    56,   -23,    -1,   -67,   645,   608,   -67,    68,
      68,   -67,   -67,   -67,   -67,     3,    11,     3,    22,    22,
     -67,   -67,   -67,   -67,    94,   614,   259,   105,   -67,   -23,
     -23,    55,   109,   564,   -67,   103,   -67,   -67,   -67,   114,
     564,   645,   645,   -67,   564,   320,   -23,   -23,   564,   381,
      34,    76,   564,   -67,   645,   119,   442,   -67,   -67,   -67,
     -67,   -67,    97,   564,   503,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   126,   -67,   -45,   -17,   -67,   -67,
     -67,    32,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -66,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -58,   -13,   -67,   -24,
     -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      58,    96,   101,    61,    63,    64,    72,    66,   133,    17,
      93,    18,    17,     3,    76,    73,    74,     4,    20,    62,
      87,    88,    99,    94,    78,    79,    80,    81,    82,    83,
      73,    74,    78,    79,    80,    81,    82,    83,    75,    85,
      56,    30,     7,    56,    30,   132,    58,    17,    53,    18,
     126,    89,    90,   120,   121,   122,    20,    54,   103,   106,
      60,    91,   107,   118,   119,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    68,    65,    76,    69,    56,    30,
      70,   125,    76,    71,   158,    77,    95,    92,   145,   155,
      58,    80,    81,    82,    83,   149,    97,   100,   103,   152,
     108,   123,   127,   156,   128,    72,   131,   136,   140,    76,
      78,    79,    80,    81,    82,    83,   141,   142,   164,   143,
     144,   146,    98,   148,    84,    85,   160,   159,    76,    86,
     163,     8,    76,   154,    58,    76,   134,     0,     0,    76,
     124,    10,    11,    12,     0,    13,     0,    76,     0,     0,
      14,     0,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,    18,     0,     0,     0,    19,     0,     0,    20,     0,
       0,    21,    22,     0,    23,    24,    25,     0,     0,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      29,    30,    10,    11,    12,     0,    13,     0,     0,     0,
       0,    14,   129,    15,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,    18,     0,     0,     0,    19,     0,     0,    20,
       0,     0,    21,    22,     0,    23,    24,    25,     0,     0,
      26,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,    30,    10,    11,    12,   138,    13,     0,     0,
       0,     0,    14,     0,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,    18,     0,     0,     0,    19,     0,     0,
      20,     0,     0,    21,    22,     0,    23,    24,    25,     0,
       0,    26,     0,     0,     0,     0,    27,    28,     0,     0,
       0,     0,    29,    30,    10,    11,    12,   153,    13,     0,
       0,     0,     0,    14,     0,    15,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,    18,     0,     0,     0,    19,     0,
       0,    20,     0,     0,    21,    22,     0,    23,    24,    25,
       0,     0,    26,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,    30,    10,    11,    12,   157,    13,
       0,     0,     0,     0,    14,     0,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,    18,     0,     0,     0,    19,
       0,     0,    20,     0,     0,    21,    22,     0,    23,    24,
      25,     0,     0,    26,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    29,    30,    10,    11,    12,   161,
      13,     0,     0,     0,     0,    14,     0,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,    18,     0,     0,     0,
      19,     0,     0,    20,     0,     0,    21,    22,     0,    23,
      24,    25,     0,     0,    26,     0,     0,     0,     0,    27,
      28,     0,     0,     0,     0,    29,    30,    10,    11,    12,
     165,    13,     0,     0,     0,     0,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,    18,     0,     0,
       0,    19,     0,     0,    20,     0,     0,    21,    22,     0,
      23,    24,    25,     0,     0,    26,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    29,    30,    10,    11,
      12,     0,    13,     0,     0,     0,     0,    14,     0,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,    18,     0,
       0,     0,    19,     0,     0,    20,     0,     0,    21,    22,
       0,    23,    24,    25,     0,     0,    26,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    29,    30,    78,
      79,    80,    81,    82,    83,    78,    79,    80,    81,    82,
      83,     0,     0,    84,    85,     0,     0,     0,    86,    84,
      85,     0,     0,     0,    86,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,   137,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,     0,    86
};

static const yytype_int16 yycheck[] =
{
      13,    59,    68,    16,    17,    18,    18,    20,     9,    32,
      55,    34,    32,     0,    31,    42,    43,    10,    41,     4,
      27,    28,    67,    50,    21,    22,    23,    24,    25,    26,
      42,    43,    21,    22,    23,    24,    25,    26,    50,    36,
      63,    64,    63,    63,    64,   103,    59,    32,    63,    34,
      95,    29,    30,    89,    90,    91,    41,    63,    59,    72,
      63,    39,    75,    87,    88,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    32,    63,    93,    63,    63,    64,
      63,    94,    99,    60,   150,    20,    11,    18,   133,   147,
     103,    23,    24,    25,    26,   140,    63,    63,    59,   144,
      20,    64,     6,   148,    33,    18,    50,    13,     3,   126,
      21,    22,    23,    24,    25,    26,   129,   130,   163,    64,
      11,    18,    33,     9,    35,    36,     7,    51,   145,    40,
      33,     5,   149,   146,   147,   152,   104,    -1,    -1,   156,
       3,     4,     5,     6,    -1,     8,    -1,   164,    -1,    -1,
      13,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    41,
      -1,    -1,    44,    45,    -1,    47,    48,    49,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    13,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    44,    45,    -1,    47,    48,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    13,    -1,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    13,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    44,    45,    -1,    47,    48,
      49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    13,    -1,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    13,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    44,    45,    -1,
      47,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    13,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,
      -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    44,    45,
      -1,    47,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    21,
      22,    23,    24,    25,    26,    21,    22,    23,    24,    25,
      26,    -1,    -1,    35,    36,    -1,    -1,    -1,    40,    35,
      36,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    51,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,    69,     0,    10,    70,    71,    63,    71,    72,
       4,     5,     6,     8,    13,    15,    16,    32,    34,    38,
      41,    44,    45,    47,    48,    49,    52,    57,    58,    63,
      64,    73,    74,    75,    76,    79,    80,    81,    82,    83,
      85,    88,    92,    93,    96,    98,   100,   101,   102,   104,
     105,   106,   107,    63,    63,    86,    63,   103,   104,    84,
      63,   104,     4,   104,   104,    63,   104,    99,    32,    63,
      63,    60,    18,    42,    43,    50,    74,    20,    21,    22,
      23,    24,    25,    26,    35,    36,    40,    27,    28,    29,
      30,    39,    18,    73,    50,    11,   103,    63,    33,    73,
      63,    92,    94,    59,    77,    78,   104,   104,    20,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   106,   106,
     107,   107,   107,    64,     3,   104,    73,     6,    33,    14,
      89,    50,   103,     9,    78,    51,    13,    51,     7,    97,
       3,   104,   104,    64,    11,    73,    18,    87,     9,    73,
      90,    95,    73,     7,   104,   103,    73,     7,    92,    51,
       7,     7,    91,    33,    73,     7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 159 "yacc.y"
    {
			gen(jmp, 0, 1); 
		;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 170 "yacc.y"
    {                 
		       strcpy(id, (yyvsp[(2) - (2)].ident)); 
	               add = cx;  
		       enter(procedure); 
		;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 176 "yacc.y"
    {
			ff=cx;
			gen(jmp, 0, cx+1); 
		;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 212 "yacc.y"
    {
		int i=0;
		
		strcpy(id,(yyvsp[(2) - (2)].ident));
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
              ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 235 "yacc.y"
    {
			int x=0;
			while(link!=0){
				x=code[link].a;
				code[link].a=cx;
				link=x;
			}
			link=0;
		;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 253 "yacc.y"
    {
			gen(jmp,0,link);
			link=cx-1;
			code[(yyvsp[(2) - (4)].number)].a=cx;
		;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 268 "yacc.y"
    {
			int i;
			strcpy(id,(yyvsp[(1) - (6)].ident));
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
		;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 289 "yacc.y"
    {	
			flag1=cx;
			gen(jmp,0,0);
		;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 297 "yacc.y"
    {
			flag2=cx;
			gen(jmp,0,0);
		;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 306 "yacc.y"
    {
			gen(ext,0,0);
		;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 314 "yacc.y"
    {
			(yyval.number)=cx;
		;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 319 "yacc.y"
    {			
			gen(jmp,0,(yyvsp[(2) - (7)].number));
			code[(yyvsp[(3) - (7)].number)].a=cx;
			if(flag1!=-1)
				code[flag1].a=cx;
			if(flag2!=-1)
				code[flag2].a=(yyvsp[(2) - (7)].number);
		;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 330 "yacc.y"
    {
			(yyval.number)=cx;
		;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 335 "yacc.y"
    {
			(yyval.number)=cx;
		;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 339 "yacc.y"
    {
		        gen(jmp,0,(yyvsp[(2) - (8)].number));
			code[(yyvsp[(7) - (8)].number)].a=cx;
			if(flag1!=-1)
				code[flag1].a=cx;
			if(flag2!=-1)
				code[flag2].a=(yyvsp[(6) - (8)].number);
		;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 350 "yacc.y"
    {
			(yyval.number)=cx;
		;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 354 "yacc.y"
    {
			(yyval.number)=cx;
			gen(jpc,0,0);
			gen(jmp,0,0);
		;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 360 "yacc.y"
    {
			gen(jmp,0,(yyvsp[(4) - (7)].number));			
			code[(yyvsp[(6) - (7)].number)+1].a=cx;
		;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 365 "yacc.y"
    {
			gen(jmp,0,(yyvsp[(6) - (11)].number)+2);
			code[(yyvsp[(6) - (11)].number)].a=cx;
			if(flag1!=-1)
				code[flag1].a=cx;
			if(flag2!=-1)
				code[flag2].a=(yyvsp[(4) - (11)].number);
		;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 377 "yacc.y"
    {
			int i=0,a=0,b=0;
			strcpy(id,(yyvsp[(1) - (3)].ident));
			a=ifconst(id);	
			i=position(id);
			if(a==1)
			{
			   yyerror("constant number!");
			   break;
			}
			b=ifbooltype(id);
			printf( "$<number>3=%d\n", (yyvsp[(3) - (3)].number));
			if(b==1 && ((yyvsp[(3) - (3)].number)!=1 && (yyvsp[(3) - (3)].number)!=0))
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
		;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 404 "yacc.y"
    {
			int i=0;
			strcpy(id,(yyvsp[(2) - (2)].ident));
			i=position(id);
			i=enter(booltype);


		;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 415 "yacc.y"
    {
			strcpy(id,(yyvsp[(2) - (2)].ident));
			enter(array);
		;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 421 "yacc.y"
    {	
			tx += (yyvsp[(5) - (5)].number);
		;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 427 "yacc.y"
    {
			int i=0;
			strcpy(id,(yyvsp[(2) - (4)].ident));
			i=position(id);
			num=(yyvsp[(4) - (4)].number);
			if(i==0){
				i=enter(constant);
			}
			if(i!=0){
				 yyerror("Already exist!");
				 break;
			}
		;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 444 "yacc.y"
    {
			code[(yyvsp[(2) - (5)].number)].a=cx;
		;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 449 "yacc.y"
    {
    		(yyval.number)=cx;
			code[(yyvsp[(2) - (4)].number)].a=cx+1;
			gen(jmp,0,0); 
    	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 455 "yacc.y"
    {
    		code[(yyvsp[(5) - (8)].number)].a=cx;
    	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 462 "yacc.y"
    {
			(yyval.number)=cx;
		;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 466 "yacc.y"
    {
			gen(jpc,0,(yyvsp[(2) - (5)].number));
		;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 473 "yacc.y"
    {
			int i;
			strcpy(id,(yyvsp[(2) - (2)].ident));
			i=position(id);
			if(i==0)
			{
				i=enter(variable);
			}
			gen(opr,0,16);
			gen(sto,0,table[i].adr);
		;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 488 "yacc.y"
    { 
			gen(opr,0,14);
			gen(opr,0,15);
		;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 496 "yacc.y"
    {		
			strcpy(id,(yyvsp[(2) - (2)].ident));
			pp=position(id);
			if(pp==0)
				yyerror("not inent");
			//printf( "pp=%d\n", pp);
			else
			gen(opr, 0, 30);
		;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 509 "yacc.y"
    {
			(yyval.number)=cx;
			gen(jpc, 0, 0);
		;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 517 "yacc.y"
    { gen(opr,0,8); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 519 "yacc.y"
    { gen(opr,0,9); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 521 "yacc.y"
    { gen(opr,0,10); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 523 "yacc.y"
    { gen(opr,0,11); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 525 "yacc.y"
    { gen(opr,0,12); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 527 "yacc.y"
    { gen(opr,0,13); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 529 "yacc.y"
    { gen(opr,0,18); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 531 "yacc.y"
    { gen(opr,0,19); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 533 "yacc.y"
    { gen(opr,0,20); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 535 "yacc.y"
    { gen(opr,0,21); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 537 "yacc.y"
    { gen(opr,0,6); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 544 "yacc.y"
    { gen(opr, 0, 2); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 546 "yacc.y"
    { gen(opr, 0, 3); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 553 "yacc.y"
    { gen(opr, 0, 4); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 555 "yacc.y"
    { gen(opr, 0, 5); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 557 "yacc.y"
    { gen(opr,0,17);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 565 "yacc.y"
    {
			int num;
			num=(yyvsp[(1) - (1)].number);
			if(num>2000000000){
				yyerror("too big int");
				num=0;
			}
			gen(lit, 0, (yyvsp[(1) - (1)].number));
		;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 575 "yacc.y"
    {
			int i;
			strcpy(id,(yyvsp[(1) - (1)].ident));
			i=position(id);
			if(i==0)
			{
				i=enter(variable);
			}
			gen(lod,0,i);
		;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 589 "yacc.y"
    {
			int i;
			strcpy(id,(yyvsp[(1) - (4)].ident));
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
		;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 606 "yacc.y"
    {
			gen(lodc, 0, 0);
		;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 610 "yacc.y"
    {
			int i;
			strcpy(id,(yyvsp[(1) - (2)].ident));
			i=position(id);
			if(i==0)
				yyerror("not define");
			else
				gen(lod,0,table[i].adr);
			gen(opr,0,22);	
			gen(sto,0,table[i].adr);
		;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 623 "yacc.y"
    {
			int i;
			strcpy(id,(yyvsp[(1) - (2)].ident));
			i=position(id);
			if(i==0)
				yyerror("not define");
			else
				gen(lod,0,table[i].adr);
			gen(opr,0,23);	
			gen(sto,0,table[i].adr);
		;}
    break;



/* Line 1455 of yacc.c  */
#line 2367 "yacc.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 639 "yacc.y"

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




