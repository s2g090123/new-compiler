/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOL = 258,
    BREAK = 259,
    CHAR = 260,
    CONTINUE = 261,
    DO = 262,
    ELSE = 263,
    ENUM = 264,
    EXTERN = 265,
    FALSE = 266,
    FLOAT = 267,
    FOR = 268,
    FN = 269,
    IF = 270,
    IN = 271,
    INT = 272,
    LET = 273,
    LOOP = 274,
    MATCH = 275,
    MUT = 276,
    PRINT = 277,
    PRINTLN = 278,
    PUB = 279,
    RETURN = 280,
    SELF = 281,
    STATIC = 282,
    STRUCT = 283,
    STR = 284,
    TRUE = 285,
    USE = 286,
    WHERE = 287,
    WHILE = 288,
    PLUS_PLUS = 289,
    MINUS_MINUS = 290,
    LE = 291,
    GE = 292,
    EQ = 293,
    NE = 294,
    PLUS_EQ = 295,
    MINUS_EQ = 296,
    MUL_EQ = 297,
    DIV_EQ = 298,
    AND = 299,
    OR = 300,
    INTEGER = 301,
    Float = 302,
    NAME = 303,
    STRING = 304,
    UMINUS = 305
  };
#endif
/* Tokens.  */
#define BOOL 258
#define BREAK 259
#define CHAR 260
#define CONTINUE 261
#define DO 262
#define ELSE 263
#define ENUM 264
#define EXTERN 265
#define FALSE 266
#define FLOAT 267
#define FOR 268
#define FN 269
#define IF 270
#define IN 271
#define INT 272
#define LET 273
#define LOOP 274
#define MATCH 275
#define MUT 276
#define PRINT 277
#define PRINTLN 278
#define PUB 279
#define RETURN 280
#define SELF 281
#define STATIC 282
#define STRUCT 283
#define STR 284
#define TRUE 285
#define USE 286
#define WHERE 287
#define WHILE 288
#define PLUS_PLUS 289
#define MINUS_MINUS 290
#define LE 291
#define GE 292
#define EQ 293
#define NE 294
#define PLUS_EQ 295
#define MINUS_EQ 296
#define MUL_EQ 297
#define DIV_EQ 298
#define AND 299
#define OR 300
#define INTEGER 301
#define Float 302
#define NAME 303
#define STRING 304
#define UMINUS 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 83 "hw2.y" /* yacc.c:1909  */

	struct{
		int tokentype; // 0:int 1:float 2:char 3:string 4:bool
		union{
			int intval;
			float floatval;
			char* stringval;
			bool boolval;
		};
	}Token;

#line 166 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
