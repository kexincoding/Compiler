/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
/* Tokens.  */
#define SYM_begin 258
#define SYM_call 259
#define SYM_const 260
#define SYM_do 261
#define SYM_end 262
#define SYM_if 263
#define SYM_else 264
#define SYM_procedure 265
#define SYM_then 266
#define SYM_var 267
#define SYM_while 268
#define SYM_until 269
#define SYM_read 270
#define SYM_write 271
#define SYM_comma 272
#define SYM_becomes 273
#define SYM_period 274
#define SYM_semicolon 275
#define SYM_eql 276
#define SYM_neq 277
#define SYM_lss 278
#define SYM_leq 279
#define SYM_gtr 280
#define SYM_geq 281
#define SYM_plus 282
#define SYM_minus 283
#define SYM_times 284
#define SYM_slash 285
#define SYM_abs 286
#define SYM_lparen 287
#define SYM_rparen 288
#define SYM_not 289
#define SYM_or 290
#define SYM_and 291
#define SYM_int 292
#define SYM_bool 293
#define SYM_mod 294
#define SYM_xor 295
#define SYM_odd 296
#define SYM_dplus 297
#define SYM_dminus 298
#define SYM_exit 299
#define SYM_repeat 300
#define SYM_util 301
#define SYM_break 302
#define SYM_continue 303
#define SYM_for 304
#define SYM_lps 305
#define SYM_rps 306
#define SYM_array 307
#define SYM_lbr 308
#define SYM_rbr 309
#define SYM_function 310
#define SYM_declare 311
#define SYM_return 312
#define SYM_case 313
#define SYM_when 314
#define SYM_colon 315
#define LOWER_THAN_ELSE 316
#define LOW_EXP 317
#define SYM_ident 318
#define SYM_number 319
#define SYM_true 320
#define SYM_false 321




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 7 "small.y"

char *ident;
int number;



/* Line 2068 of yacc.c  */
#line 189 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


