/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 16 "hw2.y" /* yacc.c:339  */

    #include<iostream>
    #include<string>
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    using namespace std;
	FILE *javacode;
    #define Trace(t) printf(t)
    typedef  struct {				// declare the symbol table type and its member;
		string name;					// the symbol's name(id function argument)
		string function_content;    	// for function_invoke's name and argument type
		int is_global; 					// 0:local 1:global  (let me know what the block is?)
		int stackindex; 				// the symbol in stack number
		int thestate; 					// 0:constant 1:variable
		int array_or_not; 				// 0:not array 1:array
		int thetype; 					// 0:int 1:float 2:char 3:string 4:bool
		int array_count;				// if the symbol is an array what size it is?
			int theint;					// under this is symbol's value
			float thefloat;
			string thestring;
			bool thebool;
			int *int_array;
			float *float_array;
			string *string_array;
			bool *bool_array;
    }symtab;
	symtab *argu;					// the argument table
	int totalargu = 0;
    symtab *thetab[256];			// the id table
    symtab funtab[256];				// the function table
    int idcount[256]={0};
    int functioncount = 0;
	int functionstatetype = 5;		// let me know what the type in this function. default is 5(void)
    int tabcount = 0;				// the total table number
	int statecount =0;				// to record the function's state number,if it is 0 it is error
	int stackcount = 0;				// to record the stack has been already haven in this function
	int label_stack[100];   		// for the situation has many if-else whiles,so i must save the next else's or outside label
	int label_top = 1;      		// the label_stack pointer,points the stack top,the top-1 is the newest label
	int label_counter = 0;  		// the total label
	int is_const = 0;       		// avoid declare const print ipush
	int is_local = 0;				// avoid declare global variable print ipush
    string temp_content="";    		// the temp for the function content
	void createtab(int tabcount);	// create the symbol table
	symtab returnsymbol(char *id);	// get the symbol's information
    void dump(int tabcount);		// print the symbol table's information
	void argudump();
	void functiondump();
    void insert(int tabcount,char *id,int check,int array_check);					// insert the id
	void insert(int tabcount,char *id,int type,int check,int array_check);
	void insertargu(string id,int type);
    void insertfunction(char *id,int type);
    int returnindex(int tabcount,char *id);						// get the id's index that it is in the symbol table
    int returntype(int tabcount,char *id);						// get the symbol table's type
	int return_constant_or_variable(int tabcount,char *id);		// get the symbol is constant or variable
    int returnfunctiontype(char *id);
	symtab returnfunctiontable(char *id);						// get the function table's information
    int insertcheck(int tabcount,char *id);						// to avoid id's value if it is a constant
    void insertvalue(int tabcount,char *id,int temp);			// insert id's value
    void insertvalue(int tabcount,char *id,float temp);
    void insertvalue(int tabcount,char *id,char *temp);
    void insertvalue(int tabcount,char *id,bool temp);
    void insertarray(int tabcount,char *id,int Type,int size,int array_check,const char *theblank);		// to create an array
    void insertarrayvalue(int tabcount,char *id,int position,int temp);									// insert this array's information
    void insertarrayvalue(int tabcount,char *id,int position,float temp);
    void insertarrayvalue(int tabcount,char *id,int position,char *temp);
    void insertarrayvalue(int tabcount,char *id,int position,bool temp);
    extern "C" {
	    int yyerror(const char *msg);
	    int yylex();
    }
    //FILE *yyin;

#line 140 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 90 "hw2.y" /* yacc.c:355  */

	struct{
		int tokentype; // 0:int 1:float 2:char 3:string 4:bool
		union{
			int intval;
			float floatval;
			char* stringval;
			bool boolval;
		};
	}Token;

#line 292 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 309 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   485

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  237

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,     2,     2,    56,     2,     2,
      59,    60,    54,    52,    63,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    61,
      51,    65,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,     2,    62,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   125,   126,   128,   129,   132,   131,   170,
     169,   184,   183,   219,   218,   240,   241,   242,   243,   245,
     246,   248,   259,   292,   322,   323,   325,   326,   328,   329,
     330,   332,   332,   357,   357,   383,   420,   457,   464,   477,
     495,   513,   531,   549,   550,   551,   552,   554,   555,   556,
     557,   558,   560,   607,   637,   662,   663,   665,   664,   670,
     669,   693,   692,   716,   734,   753,   753,   756,   757,   758,
     785,   812,   839,   866,   878,   895,   921,   930,   931,  1011,
    1071,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1102,  1101,  1109,  1110,  1112,  1111,  1118,  1117,  1124,  1123,
    1130,  1129,  1136,  1199,  1255,  1311,  1374,  1430,  1486,  1530,
    1574,  1588,  1589,  1592,  1598,  1591,  1605,  1612,  1620,  1621,
    1622,  1623
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "BREAK", "CHAR", "CONTINUE",
  "DO", "ELSE", "ENUM", "EXTERN", "FALSE", "FLOAT", "FOR", "FN", "IF",
  "IN", "INT", "LET", "LOOP", "MATCH", "MUT", "PRINT", "PRINTLN", "PUB",
  "RETURN", "SELF", "STATIC", "STRUCT", "STR", "TRUE", "USE", "WHERE",
  "WHILE", "PLUS_PLUS", "MINUS_MINUS", "LE", "GE", "EQ", "NE", "PLUS_EQ",
  "MINUS_EQ", "MUL_EQ", "DIV_EQ", "AND", "OR", "INTEGER", "Float", "NAME",
  "STRING", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
  "UMINUS", "'('", "')'", "';'", "'}'", "','", "':'", "'='", "'['", "']'",
  "'{'", "$accept", "start", "program", "function_dec", "function", "$@1",
  "$@2", "$@3", "$@4", "function_block", "return", "arguments", "argument",
  "function_return", "function_invoke", "declarations", "declaration",
  "constant", "$@5", "$@6", "variable", "array", "scopecontent",
  "statement", "$@7", "$@8", "$@9", "print_content", "block", "$@10",
  "expression", "string_expression", "int_expression", "if_statement",
  "$@11", "else_statement", "$@12", "$@13", "$@14", "$@15",
  "bool_expression", "loop_statement", "$@16", "$@17", "while_content",
  "Type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      62,    60,    43,    45,    42,    47,    37,    33,   305,    40,
      41,    59,   125,    44,    58,    61,    91,    93,   123
};
# endif

#define YYPACT_NINF -196

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-196)))

#define YYTABLE_NINF -97

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   -47,   -18,    14,  -196,  -196,     3,     3,    42,   -32,
     -28,    18,    13,    35,    11,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,   -25,    81,    15,  -196,    21,    37,    32,    43,
      15,    63,    74,  -196,  -196,  -196,  -196,    33,    63,    15,
      65,    49,    79,    71,    69,  -196,  -196,  -196,  -196,    75,
    -196,    63,    63,    63,   316,  -196,  -196,    80,   104,   107,
     121,  -196,   316,  -196,    15,  -196,  -196,   -20,   126,    49,
    -196,    63,   393,  -196,  -196,   241,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,   394,
     397,   409,   412,    63,  -196,    66,    63,  -196,   137,    15,
    -196,   316,  -196,  -196,   393,   393,   101,  -196,   429,   429,
     429,   429,   346,   337,   429,   429,    73,    73,  -196,  -196,
    -196,   130,   351,   133,   356,   138,   361,   139,   377,   316,
      49,   144,  -196,   145,  -196,   113,    66,  -196,    66,  -196,
    -196,   316,   158,  -196,  -196,   420,   393,   393,   393,   393,
     393,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,    63,    91,   160,    63,   162,   112,   393,  -196,  -196,
    -196,    49,  -196,   108,   108,  -196,  -196,  -196,   316,   164,
      63,  -196,   157,    63,   178,    63,     5,   165,   199,   382,
    -196,  -196,   266,  -196,   291,  -196,   167,    48,  -196,  -196,
     175,    -7,   180,   181,  -196,  -196,   185,   136,    63,   217,
     184,  -196,  -196,  -196,    -7,  -196,    63,   220,   179,   240,
    -196,   200,  -196,  -196,  -196,    49,   103,   193,  -196,   201,
    -196,    49,   103,  -196,   204,  -196,  -196
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     0,    26,     0,
       0,     0,     0,     0,     0,     1,     6,     3,    27,    28,
      29,    30,     0,    37,     0,    31,     0,    13,     0,    20,
       0,     0,     0,   121,   119,   118,   120,     0,     0,     0,
       0,     0,    11,     0,    38,   112,   111,    76,    77,    78,
      80,     0,     0,     0,    35,    67,    68,     0,     0,     0,
       0,    33,    32,    21,     0,    65,    14,     0,     0,     0,
      19,     0,     0,    74,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    51,    18,    16,     0,     0,
      12,    36,    88,    89,     0,     0,     0,    75,   104,   103,
     102,   105,   108,   109,   106,   107,    69,    70,    71,    72,
      73,    89,     0,    89,     0,    89,     0,    89,     0,    34,
       0,     0,    57,    61,   113,     0,    49,    66,    50,    55,
      56,    17,     0,     7,    86,     0,     0,     0,     0,     0,
       0,    79,    42,    46,    40,    44,    39,    43,    41,    45,
      10,     0,     0,     0,     0,     0,     0,     0,    47,    48,
      15,     0,    87,    81,    82,    83,    84,    85,     0,    68,
       0,    58,     0,     0,     0,     0,    78,     0,     0,     0,
       8,    90,     0,    63,     0,    62,    68,     0,    53,    52,
       0,     0,    75,     0,   114,    23,     0,    25,     0,    93,
       0,    91,    64,    60,     0,    22,     0,     0,   100,    92,
     117,     0,   115,    24,    54,     0,     0,    98,   116,     0,
     101,     0,     0,    97,     0,    99,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,   176,  -196,  -196,  -196,  -196,  -196,   -67,
    -196,   224,  -196,  -196,    52,    28,  -196,  -196,  -196,  -196,
    -196,  -196,   -56,  -195,  -196,  -196,  -196,  -196,  -101,  -196,
     -31,  -196,   -80,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -127,  -196,  -196,  -196,  -196,   -26
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,   171,   130,    69,    41,    66,
      98,    28,    29,   187,   206,   136,     8,     9,    38,    93,
      10,    11,   137,   138,   162,   163,   164,   181,    67,    95,
     178,    55,   106,   139,   201,   211,   231,   225,   232,   226,
      56,   140,   165,   214,   222,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    12,   100,    13,    44,    96,   209,    62,   131,   122,
     124,   126,   128,    63,    15,   132,   133,     1,    33,   220,
      73,    74,    75,    26,   144,   145,   134,    34,     7,    19,
      14,   230,    35,    20,   179,    27,    18,   235,    94,     1,
     101,   135,    97,     2,    36,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   196,    45,
       2,    65,   129,   160,   197,   141,   173,   174,   175,   176,
     177,    72,    22,   143,    45,    24,    25,    57,    46,    21,
     168,   131,   169,    23,     2,    39,    58,   189,   132,   133,
      40,    59,    42,    46,    47,    48,    49,    50,    61,   134,
     210,    51,    45,    60,   190,    52,    43,    53,   205,    47,
      48,    49,    50,   221,   135,    64,    51,    65,   131,    26,
      52,    46,    53,    45,   229,   132,   133,    86,    87,    88,
     234,   182,    68,   184,    71,   188,   134,    47,    48,    49,
      50,    72,    46,    89,    51,    30,    31,    32,    52,   192,
     180,   135,   194,   146,   147,   148,   149,   150,    47,    48,
     186,    50,   148,   149,   150,    51,   207,    90,   151,    52,
      91,    53,    76,    77,    78,    79,    99,   217,   166,   167,
      80,    81,    16,    17,    92,   207,    82,    83,    84,    85,
      86,    87,    88,    76,    77,    78,    79,   152,   142,   216,
     154,    80,    81,   161,   -59,   156,   158,    82,    83,    84,
      85,    86,    87,    88,    76,    77,    78,    79,   193,   183,
     170,   185,    80,    81,   191,   218,   198,   204,    82,    83,
      84,    85,    86,    87,    88,    76,    77,    78,    79,   195,
     208,   212,   213,    80,    81,   215,   219,   -96,   227,    82,
      83,    84,    85,    86,    87,    88,    76,    77,    78,    79,
     199,   -94,   228,   233,    80,    81,   236,    70,   223,     0,
      82,    83,    84,    85,    86,    87,    88,    76,    77,    78,
      79,   224,     0,     0,     0,    80,    81,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,   107,    76,    77,    78,    79,     0,     0,     0,     0,
      80,    81,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,   202,    76,    77,    78,
      79,     0,     0,     0,     0,    80,    81,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,   203,    76,    77,    78,    79,     0,     0,     0,     0,
      80,    81,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    76,    77,    78,    79,     0,     0,     0,
       0,    80,    76,    77,    78,    79,     0,    82,    83,    84,
      85,    86,    87,    88,     0,     0,    82,    83,    84,    85,
      86,    87,    88,   146,   147,   148,   149,   150,   146,   147,
     148,   149,   150,   146,   147,   148,   149,   150,   153,     0,
       0,     0,     0,   155,     0,     0,     0,     0,   157,   146,
     147,   148,   149,   150,   146,   147,   148,   149,   150,   102,
     102,   103,   121,   102,   159,   123,   104,   104,     0,   200,
     104,     0,   105,   105,     0,   102,   105,   125,   102,     0,
     127,     0,   104,     0,     0,   104,     0,     0,   105,     0,
       0,   105,   146,   147,   148,   149,   150,     0,     0,     0,
     172,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      31,    48,    69,    21,    30,    25,   201,    38,    15,    89,
      90,    91,    92,    39,     0,    22,    23,    14,     3,   214,
      51,    52,    53,    48,   104,   105,    33,    12,     0,    61,
      48,   226,    17,    61,   161,    60,     8,   232,    64,    14,
      71,    48,    62,    18,    29,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   185,    11,
      18,    68,    93,   130,    59,    96,   146,   147,   148,   149,
     150,    66,    59,    99,    11,    64,    65,     3,    30,    61,
     136,    15,   138,    48,    18,    64,    12,   167,    22,    23,
      53,    17,    60,    30,    46,    47,    48,    49,    65,    33,
     201,    53,    11,    29,   171,    57,    63,    59,    60,    46,
      47,    48,    49,   214,    48,    50,    53,    68,    15,    48,
      57,    30,    59,    11,   225,    22,    23,    54,    55,    56,
     231,   162,    53,   164,    65,   166,    33,    46,    47,    48,
      49,    66,    30,    63,    53,    64,    65,    66,    57,   180,
      59,    48,   183,    52,    53,    54,    55,    56,    46,    47,
      48,    49,    54,    55,    56,    53,   197,    63,    67,    57,
      63,    59,    36,    37,    38,    39,    50,   208,    65,    66,
      44,    45,     6,     7,    63,   216,    50,    51,    52,    53,
      54,    55,    56,    36,    37,    38,    39,    67,    61,    63,
      67,    44,    45,    59,    59,    67,    67,    50,    51,    52,
      53,    54,    55,    56,    36,    37,    38,    39,    61,    59,
      62,    59,    44,    45,    60,     8,    61,    60,    50,    51,
      52,    53,    54,    55,    56,    36,    37,    38,    39,    61,
      65,    61,    61,    44,    45,    60,    62,    68,     8,    50,
      51,    52,    53,    54,    55,    56,    36,    37,    38,    39,
      61,    68,    62,    62,    44,    45,    62,    43,   216,    -1,
      50,    51,    52,    53,    54,    55,    56,    36,    37,    38,
      39,    61,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    60,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    60,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    60,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    44,    36,    37,    38,    39,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    52,    53,    54,    55,    56,    52,    53,
      54,    55,    56,    52,    53,    54,    55,    56,    67,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    67,    52,
      53,    54,    55,    56,    52,    53,    54,    55,    56,    46,
      46,    48,    48,    46,    67,    48,    53,    53,    -1,    67,
      53,    -1,    59,    59,    -1,    46,    59,    48,    46,    -1,
      48,    -1,    53,    -1,    -1,    53,    -1,    -1,    59,    -1,
      -1,    59,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      60,    52,    53,    54,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    18,    70,    71,    72,    73,    84,    85,    86,
      89,    90,    48,    21,    48,     0,    72,    72,    84,    61,
      61,    61,    59,    48,    64,    65,    48,    60,    80,    81,
      64,    65,    66,     3,    12,    17,    29,   114,    87,    64,
      53,    77,    60,    63,   114,    11,    30,    46,    47,    48,
      49,    53,    57,    59,    99,   100,   109,     3,    12,    17,
      29,    65,    99,   114,    50,    68,    78,    97,    53,    76,
      80,    65,    66,    99,    99,    99,    36,    37,    38,    39,
      44,    45,    50,    51,    52,    53,    54,    55,    56,    63,
      63,    63,    63,    88,   114,    98,    25,    62,    79,    50,
      78,    99,    46,    48,    53,    59,   101,    60,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    48,   101,    48,   101,    48,   101,    48,   101,    99,
      75,    15,    22,    23,    33,    48,    84,    91,    92,   102,
     110,    99,    61,   114,   101,   101,    52,    53,    54,    55,
      56,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      78,    59,    93,    94,    95,   111,    65,    66,    91,    91,
      62,    74,    60,   101,   101,   101,   101,   101,    99,   109,
      59,    96,    99,    59,    99,    59,    48,    82,    99,   101,
      78,    60,    99,    61,    99,    61,   109,    59,    61,    61,
      67,   103,    60,    60,    60,    60,    83,    99,    65,    92,
      97,   104,    61,    61,   112,    60,    63,    99,     8,    62,
      92,    97,   113,    83,    61,   106,   108,     8,    62,    97,
      92,   105,   107,    62,    97,    92,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    74,    73,    75,
      73,    76,    73,    77,    73,    78,    78,    79,    79,    80,
      80,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    87,    86,    88,    86,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    93,    92,    94,
      92,    95,    92,    96,    96,    98,    97,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     103,   102,   104,   104,   105,   104,   106,   104,   107,   104,
     108,   104,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   111,   112,   110,   113,   113,   114,   114,
     114,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,    10,     0,
       9,     0,     7,     0,     6,     4,     2,     2,     1,     3,
       1,     3,     4,     3,     3,     1,     1,     2,     2,     2,
       2,     0,     5,     0,     7,     5,     7,     3,     5,     8,
       8,     8,     8,     8,     8,     8,     8,     2,     2,     1,
       1,     0,     4,     4,     7,     1,     1,     0,     3,     0,
       6,     0,     4,     2,     4,     0,     3,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     1,     4,
       1,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       0,     6,     2,     1,     0,     6,     0,     5,     0,     5,
       0,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     0,     0,     7,     2,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 123 "hw2.y" /* yacc.c:1646  */
    {if(functioncount==0)yyerror("no function error");cout<<endl<<"global ";dump(tabcount);cout<<endl<<"global ";functiondump();Trace("< program reduce to start >\n");}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 125 "hw2.y" /* yacc.c:1646  */
    {Trace("< declarations function_dec reduce to program >\n");}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 126 "hw2.y" /* yacc.c:1646  */
    {Trace("< function_dec reduce to program >\n");}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 128 "hw2.y" /* yacc.c:1646  */
    {Trace("< function reduce to function_dec >\n");}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "hw2.y" /* yacc.c:1646  */
    {Trace("< function function_dec reduce to function_dec >\n");}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "hw2.y" /* yacc.c:1646  */
    {
			is_local = 1;								// tell us it is in a function(local) now
			functionstatetype = (yyvsp[0].Token).tokentype;
			if((yyvsp[0].Token).tokentype==0)
				fprintf(javacode,"\tmethod public static int %s(",(yyvsp[-6].Token).stringval);
			else if((yyvsp[0].Token).tokentype==4)
				fprintf(javacode,"\tmethod public static int %s(",(yyvsp[-6].Token).stringval);
			for(int i =0;i<totalargu;i++)				// under this,if this function has argument, to store the argument information that to print the jasm,ex: method public static int add("int, int)"
			{
				if(argu[i].thetype==0)
				{
					fprintf(javacode,"int");
					temp_content +="int";
				}	
				else if(argu[i].thetype==4)
				{
					fprintf(javacode,"bool");
					temp_content +="bool";
				}	
				if(i!=totalargu-1)
				{
					fprintf(javacode,", ");
					temp_content += ", ";
				}	
				else
				{
					fprintf(javacode,")\n");
					temp_content += ")";
				}	
			}
			insertfunction((yyvsp[-6].Token).stringval,(yyvsp[0].Token).tokentype);
			temp_content="";
			fprintf(javacode,"\tmax_stack 15\n");
			fprintf(javacode,"\tmax_locals 15\n");
			fprintf(javacode,"\t{\n");
		  }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 168 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).stringval=(yyvsp[-8].Token).stringval;argudump();Trace("< FN NAME '(' argument ')' '-' '>' Type block reduce to function >\n");}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 170 "hw2.y" /* yacc.c:1646  */
    {
			is_local = 1;
			functionstatetype = (yyvsp[0].Token).tokentype;
			insertfunction((yyvsp[-5].Token).stringval,(yyvsp[0].Token).tokentype);
			if((yyvsp[0].Token).tokentype==0)
				fprintf(javacode,"\tmethod public static int %s()\n",(yyvsp[-5].Token).stringval);
			else if((yyvsp[0].Token).tokentype==4)
				fprintf(javacode,"\tmethod public static int %s()\n",(yyvsp[-5].Token).stringval);
			fprintf(javacode,"\tmax_stack 15\n");
			fprintf(javacode,"\tmax_locals 15\n");
			fprintf(javacode,"\t{\n");
		  }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 182 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).stringval=(yyvsp[-7].Token).stringval;Trace("< FN NAME '(' ')' '-' '>' Type block reduce to function >\n");}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 184 "hw2.y" /* yacc.c:1646  */
    {
			is_local = 1;
			functionstatetype = 5;
			fprintf(javacode,"\tmethod public static void %s(",(yyvsp[-3].Token).stringval);
			for(int i =0;i<totalargu;i++)
			{
				if(argu[i].thetype==0)
				{
					fprintf(javacode,"int");
					temp_content +="int";
				}	
				else if(argu[i].thetype==4)
				{
					fprintf(javacode,"bool");
					temp_content +="bool";
				}	
				if(i!=totalargu-1)
				{
					fprintf(javacode,", ");
					temp_content += ", ";
				}	
				else
				{
					fprintf(javacode,")\n");
					temp_content += ")";
				}	
			}
			insertfunction((yyvsp[-3].Token).stringval,5);
			temp_content="";
			fprintf(javacode,"\tmax_stack 15\n");
			fprintf(javacode,"\tmax_locals 15\n");
			fprintf(javacode,"\t{\n");
		}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 217 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).stringval=(yyvsp[-5].Token).stringval;argudump();Trace("< FN NAME '(' argument ')' block reduce to function >\n");}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 219 "hw2.y" /* yacc.c:1646  */
    {
			is_local = 1;
			functionstatetype = 5;
			insertfunction((yyvsp[-2].Token).stringval,5);
			if(strcmp((yyvsp[-2].Token).stringval,"main")==0)
			{
				fprintf(javacode,"\tmethod public static void main(java.lang.String[])\n");
				fprintf(javacode,"\tmax_stack 15\n");
				fprintf(javacode,"\tmax_locals 15\n");
				fprintf(javacode,"\t{\n");
			}
			else
			{
				fprintf(javacode,"\tmethod public static void %s()\n",(yyvsp[-2].Token).stringval);
				fprintf(javacode,"\tmax_stack 15\n");
				fprintf(javacode,"\tmax_locals 15\n");
				fprintf(javacode,"\t{\n");
			}
		}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 238 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).stringval=(yyvsp[-4].Token).stringval;Trace("< FN NAME '(' ')' block reduce to function >\n");}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 240 "hw2.y" /* yacc.c:1646  */
    {is_local = 0;/* it tell us I go in to the function block(in local)*/ stackcount=0;Trace("< block return ';' '}' reduce to function_block >\n");}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 241 "hw2.y" /* yacc.c:1646  */
    {is_local = 0;if(statecount==0)yyerror("no statement error");fprintf(javacode,"\t\treturn\n\t}\n");stackcount=0;Trace("< block '}' reduce to function_block >\n");}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 242 "hw2.y" /* yacc.c:1646  */
    {if(functionstatetype!=5)fprintf(javacode,"\t\tireturn\n\t}\n");else fprintf(javacode,"\t\treturn\n\t}\n");Trace("< RETURN expression reduce to return >\n");}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 243 "hw2.y" /* yacc.c:1646  */
    {if(functionstatetype!=5)fprintf(javacode,"\t\tireturn\n\t}\n");else fprintf(javacode,"\t\treturn\n\t}\n");Trace("< RETURN reduce to return >\n");}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 245 "hw2.y" /* yacc.c:1646  */
    {Trace("< argument ',' arguments reduce to arguments >\n");}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 246 "hw2.y" /* yacc.c:1646  */
    {Trace("< argument reduce to arguments >\n");}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 249 "hw2.y" /* yacc.c:1646  */
    {
			if(totalargu==0)	/* tell us i go into argument scope to zero the argument number*/
			{	
				stackcount=0;
				argu = (symtab*)malloc(sizeof(symtab)*10);
			}
			insertargu((yyvsp[-2].Token).stringval,(yyvsp[0].Token).tokentype); 
			Trace("< NAME ':' Type reduce to argument >\n"); 			// this block is to declare the function argument and it reduces to argument;
		}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 260 "hw2.y" /* yacc.c:1646  */
    {
		int check = returnfunctiontype((yyvsp[-3].Token).stringval);	// ignore under this
		if(check==0)
		{
			(yyval.Token).tokentype=0;
			(yyval.Token).intval = 0;
		}
		else if(check==1)
		{
			(yyval.Token).tokentype=1;
			(yyval.Token).floatval = 0.0;
		}
		else if(check==3)
		{
			string s = "___";
			(yyval.Token).tokentype=3;
			strcpy((yyval.Token).stringval,s.c_str());
		}
		else if(check==4)
		{
			(yyval.Token).tokentype=4;
			(yyval.Token).boolval = true;
		}
		else
			yyerror("type error");					   // ignore above this
		symtab tempfunction = returnfunctiontable((yyvsp[-3].Token).stringval);
		if(tempfunction.thetype==0)						// to print the function_invoke text in jasm
			fprintf(javacode,"\t\tinvokestatic int proj3.%s(%s\n",(yyvsp[-3].Token).stringval,tempfunction.function_content.c_str());
		else if(tempfunction.thetype==4)
			fprintf(javacode,"\t\tinvokestatic bool proj3.%s(%s\n",(yyvsp[-3].Token).stringval,tempfunction.function_content.c_str());
		Trace("< NAME '(' argument ')' reduce to function_return >\n");
	}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 293 "hw2.y" /* yacc.c:1646  */
    {
		int check = returnfunctiontype((yyvsp[-2].Token).stringval);			// ignore under this 
		if(check==0)
		{
			(yyval.Token).tokentype=0;
			(yyval.Token).intval = 0;
		}
		else if(check==1)
		{
			(yyval.Token).tokentype=1;
			(yyval.Token).floatval = 0.0;
		}
		else if(check==3)
		{
			string s = "___";
			(yyval.Token).tokentype=3;
			strcpy((yyval.Token).stringval,s.c_str());
		}
		else if(check==4)
		{
			(yyval.Token).tokentype=4;
			(yyval.Token).boolval = true;
		}
		else
			yyerror("type error");							// ignore above this
		fprintf(javacode,"\t\tinvokestatic %d proj3.%s()\n",returnfunctiontype((yyvsp[-2].Token).stringval),(yyvsp[-2].Token).stringval);
		Trace("NAME '(' ')' reduce to function_return >\n");
	}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 322 "hw2.y" /* yacc.c:1646  */
    {Trace("< expression ',' function_invoke reduce to function_invoke >\n");}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 323 "hw2.y" /* yacc.c:1646  */
    {Trace("< expression reduce to function_invoke >\n");}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 325 "hw2.y" /* yacc.c:1646  */
    {Trace("< declaration reduce to declarations >\n");}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 326 "hw2.y" /* yacc.c:1646  */
    {Trace("< declaration declarations reduce to declarations >\n");}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 328 "hw2.y" /* yacc.c:1646  */
    {Trace("< constant reduce to declaration >\n");}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 329 "hw2.y" /* yacc.c:1646  */
    {Trace("< variable reduce to declaration >\n");}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 330 "hw2.y" /* yacc.c:1646  */
    {Trace("< array reduce to declaration >\n");}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 332 "hw2.y" /* yacc.c:1646  */
    {is_const=1;}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 334 "hw2.y" /* yacc.c:1646  */
    {
			insert(tabcount,(yyvsp[-3].Token).stringval,0,0);
			if((yyvsp[0].Token).tokentype==0)
			{
				insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[0].Token).intval);
			}
			else if((yyvsp[0].Token).tokentype==1)
			{
				insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[0].Token).floatval);
			}
			else if((yyvsp[0].Token).tokentype==3)
			{
				insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[0].Token).stringval);
			}
			else if((yyvsp[0].Token).tokentype==4)
			{
				insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[0].Token).boolval);
			}
			else
				yyerror("assign error");
			is_const=0;						// declare constant finish
			Trace("< LET NAME '=' expression reduece to constant >\n");
		}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 357 "hw2.y" /* yacc.c:1646  */
    {is_const = 1;}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 359 "hw2.y" /* yacc.c:1646  */
    {
			insert(tabcount,(yyvsp[-5].Token).stringval,(yyvsp[-3].Token).tokentype,0,0);
			if((yyvsp[-3].Token).tokentype==0)
			{
				insertvalue(tabcount,(yyvsp[-5].Token).stringval,(yyvsp[0].Token).intval);
			}
			else if((yyvsp[-3].Token).tokentype==1)
			{
				insertvalue(tabcount,(yyvsp[-5].Token).stringval,(yyvsp[0].Token).floatval);
			}
			else if((yyvsp[-3].Token).tokentype==3)
			{
				insertvalue(tabcount,(yyvsp[-5].Token).stringval,(yyvsp[0].Token).stringval);
			}
			else if((yyvsp[-3].Token).tokentype==4)
			{
				insertvalue(tabcount,(yyvsp[-5].Token).stringval,(yyvsp[0].Token).boolval);
			}
			else
				yyerror("assign error");
			is_const = 0;
			Trace("< LET NAME ':' Type '=' expression reduce to constant >\n");
		}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 384 "hw2.y" /* yacc.c:1646  */
    {
			insert(tabcount,(yyvsp[-2].Token).stringval,1,0);
			if((yyvsp[0].Token).tokentype==0)
			{
				insertvalue(tabcount,(yyvsp[-2].Token).stringval,(yyvsp[0].Token).intval);
				if(tabcount==0)							// to tell us ,this declartion is in global
					fprintf(javacode,"\tfield static int %s = %d\n",(yyvsp[-2].Token).stringval,(yyvsp[0].Token).intval);
				else									// to tell us ,this declartion is in local
				{
					symtab tempsym = returnsymbol((yyvsp[-2].Token).stringval);
					fprintf(javacode,"\t\tistore %d\n",tempsym.stackindex);
				}
			}
			else if((yyvsp[0].Token).tokentype==1)
			{
				insertvalue(tabcount,(yyvsp[-2].Token).stringval,(yyvsp[0].Token).floatval);
			}
			else if((yyvsp[0].Token).tokentype==3)
			{
				insertvalue(tabcount,(yyvsp[-2].Token).stringval,(yyvsp[0].Token).stringval);
			}
			else if((yyvsp[0].Token).tokentype==4)
			{
				insertvalue(tabcount,(yyvsp[-2].Token).stringval,(yyvsp[0].Token).boolval);
				if(tabcount==0)
					fprintf(javacode,"\tfield static bool %s = %d\n",(yyvsp[-2].Token).stringval,(yyvsp[0].Token).boolval);
				else
				{
					symtab tempsym = returnsymbol((yyvsp[-2].Token).stringval);
					fprintf(javacode,"\t\tistore %d\n",tempsym.stackindex);
				}
			}
			else
				yyerror("assign error");
			Trace("< LET MUT NAME '=' expression reduce to variable >\n");
		}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 421 "hw2.y" /* yacc.c:1646  */
    {
			insert(tabcount,(yyvsp[-4].Token).stringval,(yyvsp[-2].Token).tokentype,1,0);
			if((yyvsp[-2].Token).tokentype==0)
			{
				insertvalue(tabcount,(yyvsp[-4].Token).stringval,(yyvsp[0].Token).intval);
				if(tabcount==0)
					fprintf(javacode,"\tfield static int %s = %d\n",(yyvsp[-4].Token).stringval,(yyvsp[0].Token).intval);
				else
				{
					symtab tempsym = returnsymbol((yyvsp[-4].Token).stringval);
					fprintf(javacode,"\t\tistore %d\n",tempsym.stackindex);
				}
			}
			else if((yyvsp[-2].Token).tokentype==1)
			{
				insertvalue(tabcount,(yyvsp[-4].Token).stringval,(yyvsp[0].Token).floatval);
			}
			else if((yyvsp[-2].Token).tokentype==3)
			{
				insertvalue(tabcount,(yyvsp[-4].Token).stringval,(yyvsp[0].Token).stringval);
			}
			else if((yyvsp[-2].Token).tokentype==4)
			{
				insertvalue(tabcount,(yyvsp[-4].Token).stringval,(yyvsp[0].Token).boolval);
				if(tabcount==0)
					fprintf(javacode,"\tfield static bool %s = %d\n",(yyvsp[-4].Token).stringval,(yyvsp[0].Token).boolval);
				else
				{
					symtab tempsym = returnsymbol((yyvsp[-4].Token).stringval);
					fprintf(javacode,"\t\tistore %d\n",tempsym.stackindex);
				}
			}
			else
				yyerror("assign error");
			Trace("< LET MUT NAME ':' Type '=' expression reduce to variable >\n");
		}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 458 "hw2.y" /* yacc.c:1646  */
    {
			insert(tabcount,(yyvsp[0].Token).stringval,1,0);
			if(tabcount==0)
					fprintf(javacode,"\tfield static int %s\n",(yyvsp[0].Token).stringval);
			Trace("< LET MUT NAME reduce to variable >\n");
		}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 465 "hw2.y" /* yacc.c:1646  */
    {
			insert(tabcount,(yyvsp[-2].Token).stringval,(yyvsp[0].Token).tokentype,1,0);
			if(tabcount==0)
			{
				if((yyvsp[0].Token).tokentype==0)
					fprintf(javacode,"\tfield static int %s\n",(yyvsp[-2].Token).stringval);
				else if((yyvsp[0].Token).tokentype==4)
					fprintf(javacode,"\tfield static bool %s\n",(yyvsp[-2].Token).stringval);
			}
			Trace("< LET MUT NAME ':' Type reduce to variable >\n");
		}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 478 "hw2.y" /* yacc.c:1646  */
    {
		    if(return_constant_or_variable(tabcount,(yyvsp[-1].Token).stringval)==1)
				yyerror("array size is variable error");
			if(returntype(tabcount,(yyvsp[-1].Token).stringval)!=0)
				yyerror("array size is not int error");
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,(yyvsp[-1].Token).stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			insertarray(tabcount,(yyvsp[-5].Token).stringval,0,thetab[choose][index].theint,1,"___");
			Trace("< LET MUT NAME '[' INT ',' NAME ']' reduce to array >\n");
	   }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 496 "hw2.y" /* yacc.c:1646  */
    {
		    if(return_constant_or_variable(tabcount,(yyvsp[-1].Token).stringval)==1)
				yyerror("array size is variable error");
			if(returntype(tabcount,(yyvsp[-1].Token).stringval)!=0)
				yyerror("array size is not int error");
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,(yyvsp[-1].Token).stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			insertarray(tabcount,(yyvsp[-5].Token).stringval,1,thetab[choose][index].theint,1,"___");
			Trace("< LET MUT NAME '[' FLOAT ',' NAME ']' reduce to array >\n");
	   }
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 514 "hw2.y" /* yacc.c:1646  */
    {
		    if(return_constant_or_variable(tabcount,(yyvsp[-1].Token).stringval)==1)
				yyerror("array size is variable error");
			if(returntype(tabcount,(yyvsp[-1].Token).stringval)!=0)
				yyerror("array size is not int error");
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,(yyvsp[-1].Token).stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			insertarray(tabcount,(yyvsp[-5].Token).stringval,3,thetab[choose][index].theint,1,"___");
			Trace("< LET MUT NAME '[' STRING ',' NAME ']' reduce to array >\n");
	   }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 532 "hw2.y" /* yacc.c:1646  */
    {
		    if(return_constant_or_variable(tabcount,(yyvsp[-1].Token).stringval)==1)
				yyerror("array size is variable error");
			if(returntype(tabcount,(yyvsp[-1].Token).stringval)!=0)
				yyerror("array size is not int error");
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,(yyvsp[-1].Token).stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			insertarray(tabcount,(yyvsp[-5].Token).stringval,4,thetab[choose][index].theint,1,"___");
			Trace("< LET MUT NAME '[' BOOL ',' NAME ']' reduce to array >\n");
	   }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 549 "hw2.y" /* yacc.c:1646  */
    {insertarray(tabcount,(yyvsp[-5].Token).stringval,0,(yyvsp[-1].Token).intval,1,"___"); Trace("< LET MUT NAME '[' INT ',' int_expression ']' reduce to array >\n");}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 550 "hw2.y" /* yacc.c:1646  */
    {insertarray(tabcount,(yyvsp[-5].Token).stringval,1,(yyvsp[-1].Token).intval,1,"___"); Trace("< LET MUT NAME '[' FLOAT ',' int_expression ']' reduce to array >\n");}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 551 "hw2.y" /* yacc.c:1646  */
    {insertarray(tabcount,(yyvsp[-5].Token).stringval,3,(yyvsp[-1].Token).intval,1,"___"); Trace("< LET MUT NAME '[' STR ',' int_expression ']' reduce to array >\n");}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 552 "hw2.y" /* yacc.c:1646  */
    {insertarray(tabcount,(yyvsp[-5].Token).stringval,4,(yyvsp[-1].Token).intval,1,"___"); Trace("< LET MUT NAME '[' BOOL ',' int_expression ']' reduce to array >\n");}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 554 "hw2.y" /* yacc.c:1646  */
    {Trace("< declarations scopecontent reduce to scopecontent >\n");}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 555 "hw2.y" /* yacc.c:1646  */
    {Trace("< statement scopecontent reduce to scopecontent >\n");}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 556 "hw2.y" /* yacc.c:1646  */
    {Trace("< declarations reduce to scopecontent >\n");}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 557 "hw2.y" /* yacc.c:1646  */
    {Trace("< statement reduce to scopecontent >\n");}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 558 "hw2.y" /* yacc.c:1646  */
    {Trace("< empty reduce to scopecontent >\n");}
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 561 "hw2.y" /* yacc.c:1646  */
    {
			statecount = 1;								// to record there is a state in this function
			if(insertcheck(tabcount,(yyvsp[-3].Token).stringval)==1)
			{
				if((yyvsp[-1].Token).tokentype==0&&returntype(tabcount,(yyvsp[-3].Token).stringval)==0)
				{
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[-1].Token).intval);
					symtab tempsym = returnsymbol((yyvsp[-3].Token).stringval);		// find this id's information
					if(tempsym.is_global==1)							// if the id is global,I print under this in jasm
						fprintf(javacode,"\t\tputstatic int proj3.%s\n",(yyvsp[-3].Token).stringval);
					else												// if the id is local,I print under this in jasm
						fprintf(javacode,"\t\tistore %d\n",tempsym.stackindex);
				}
				else if((yyvsp[-1].Token).tokentype==1&&returntype(tabcount,(yyvsp[-3].Token).stringval)==0)
				{
					int x = (yyvsp[-1].Token).floatval;
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,x);
				}
				else if((yyvsp[-1].Token).tokentype==4&&returntype(tabcount,(yyvsp[-3].Token).stringval)==0)
				{
					int x = (yyvsp[-1].Token).boolval;
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,x);
				}
				else if((yyvsp[-1].Token).tokentype==0&&returntype(tabcount,(yyvsp[-3].Token).stringval)==1)
				{
					float x = (yyvsp[-1].Token).intval;
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,x);
				}
				else if((yyvsp[-1].Token).tokentype==1&&returntype(tabcount,(yyvsp[-3].Token).stringval)==1)
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[-1].Token).floatval);
				else if((yyvsp[-1].Token).tokentype==3&&returntype(tabcount,(yyvsp[-3].Token).stringval)==3)
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[-1].Token).stringval);
				else if((yyvsp[-1].Token).tokentype==4&&returntype(tabcount,(yyvsp[-3].Token).stringval)==4)
				{
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[-1].Token).boolval);
					symtab tempsym = returnsymbol((yyvsp[-3].Token).stringval);
					if(tempsym.is_global==1)
						fprintf(javacode,"\t\tputstatic int proj3.%s\n",(yyvsp[-3].Token).stringval);
					else
						fprintf(javacode,"\t\tistore %d\n",tempsym.stackindex);
				}
				else
					yyerror("assign error");
				Trace("< NAME '=' expression reduce to statement >\n");
			}
		}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 608 "hw2.y" /* yacc.c:1646  */
    {
			statecount = 1;
			if(insertcheck(tabcount,(yyvsp[-3].Token).stringval)==1)
			{
				if((yyvsp[-1].Token).tokentype==0)
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[-1].Token).intval);
				else if((yyvsp[-1].Token).tokentype==1)
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[-1].Token).floatval);
				else if((yyvsp[-1].Token).tokentype==3)
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[-1].Token).stringval);
				else if((yyvsp[-1].Token).tokentype==4)
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[-1].Token).boolval);
				else
					yyerror("assign error");
				symtab tempsym = returnsymbol((yyvsp[-3].Token).stringval);
				if(tempsym.is_global==1)
				{
					if(tempsym.thetype==0)
						fprintf(javacode,"\t\tputstatic int proj3.%s\n",tempsym.name.c_str());
					else if(tempsym.thetype==4)
						fprintf(javacode,"\t\tputstatic bool proj3.%s\n",tempsym.name.c_str());
				}
				else
				{
					fprintf(javacode,"\t\tistore %d\n",tempsym.stackindex);
				}
				Trace("< NAME '=' function_return reduce to statement >\n");
			}
		}
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 638 "hw2.y" /* yacc.c:1646  */
    {
			statecount = 1;
			if((yyvsp[-1].Token).tokentype==0&&returntype(tabcount,(yyvsp[-6].Token).stringval)==0)
				insertarrayvalue(tabcount,(yyvsp[-6].Token).stringval,(yyvsp[-4].Token).intval,(yyvsp[-1].Token).intval);
			else if((yyvsp[-1].Token).tokentype==0&&returntype(tabcount,(yyvsp[-6].Token).stringval)==1)
			{
				float temp = (yyvsp[-1].Token).intval;
				insertarrayvalue(tabcount,(yyvsp[-6].Token).stringval,(yyvsp[-4].Token).intval,temp);
			}
			else if((yyvsp[-1].Token).tokentype==1&&returntype(tabcount,(yyvsp[-6].Token).stringval)==0)
			{
				int temp = (yyvsp[-1].Token).floatval;
				insertarrayvalue(tabcount,(yyvsp[-6].Token).stringval,(yyvsp[-4].Token).intval,temp);
			}
			else if((yyvsp[-1].Token).tokentype==1&&returntype(tabcount,(yyvsp[-6].Token).stringval)==1)
				insertarrayvalue(tabcount,(yyvsp[-6].Token).stringval,(yyvsp[-4].Token).intval,(yyvsp[-1].Token).floatval);
			else if((yyvsp[-1].Token).tokentype==3&&returntype(tabcount,(yyvsp[-6].Token).stringval)==3)
				insertarrayvalue(tabcount,(yyvsp[-6].Token).stringval,(yyvsp[-4].Token).intval,(yyvsp[-1].Token).stringval);
			else if((yyvsp[-1].Token).tokentype==4&&returntype(tabcount,(yyvsp[-6].Token).stringval)==4)
				insertarrayvalue(tabcount,(yyvsp[-6].Token).stringval,(yyvsp[-4].Token).intval,(yyvsp[-1].Token).boolval);
			else
					yyerror("assign error");
			Trace("< NAME '[' int_expression ']' '=' expression reduce to statement >\n");
		}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 662 "hw2.y" /* yacc.c:1646  */
    {statecount = 1;Trace("< if_statement reduce to statement >\n");}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 663 "hw2.y" /* yacc.c:1646  */
    {statecount = 1;Trace("< loop_statement reduce to statement >\n");}
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 665 "hw2.y" /* yacc.c:1646  */
    {
			fprintf(javacode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 668 "hw2.y" /* yacc.c:1646  */
    {Trace("< PRINT expression reduce to statement >\n");}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 670 "hw2.y" /* yacc.c:1646  */
    {
			fprintf(javacode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		}
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 674 "hw2.y" /* yacc.c:1646  */
    {
			statecount = 1;
			if((yyvsp[-2].Token).tokentype==0)
				printf("%d\n",(yyvsp[-2].Token).intval);
			else if((yyvsp[-2].Token).tokentype==1)
				printf("%f\n",(yyvsp[-2].Token).floatval);
			else if((yyvsp[-2].Token).tokentype==3)
				printf("%s\n",(yyvsp[-2].Token).stringval);
			else if((yyvsp[-2].Token).tokentype==4)
				printf("%s\n",(yyvsp[-2].Token).boolval==true?"TRUE":"FALSE");
			else
				yyerror("println error");
			if((yyvsp[-2].Token).tokentype==0||(yyvsp[-2].Token).tokentype==4)
				fprintf(javacode,"\t\tinvokevirtual void java.io.PrintStream.println(int)\n");
			else
				fprintf(javacode,"\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n");
			Trace("< PRINT '(' expression ')' reduce to statement >\n");
		}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 693 "hw2.y" /* yacc.c:1646  */
    {
			fprintf(javacode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 697 "hw2.y" /* yacc.c:1646  */
    {
			statecount = 1;
			if((yyvsp[-1].Token).tokentype==0)
				printf("%d\n",(yyvsp[-1].Token).intval);
			else if((yyvsp[-1].Token).tokentype==1)
				printf("%f\n",(yyvsp[-1].Token).floatval);
			else if((yyvsp[-1].Token).tokentype==3)
				printf("%s\n",(yyvsp[-1].Token).stringval);
			else if((yyvsp[-1].Token).tokentype==4)
				printf("%s\n",(yyvsp[-1].Token).boolval==true?"TRUE":"FALSE");
			else
				yyerror("println error");
			if((yyvsp[-1].Token).tokentype==0||(yyvsp[-1].Token).tokentype==4)
				fprintf(javacode,"\t\tinvokevirtual void java.io.PrintStream.println(int)\n");
			else
				fprintf(javacode,"\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n");
			Trace("< PRINTLN expression reduce to statement >\n");
		}
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 717 "hw2.y" /* yacc.c:1646  */
    {
				statecount = 1;
				if((yyvsp[-1].Token).tokentype==0)
					printf("%d",(yyvsp[-1].Token).intval);
				else if((yyvsp[-1].Token).tokentype==1)
					printf("%f",(yyvsp[-1].Token).floatval);
				else if((yyvsp[-1].Token).tokentype==3)
					printf("%s",(yyvsp[-1].Token).stringval);
				else if((yyvsp[-1].Token).tokentype==4)
					printf("%s",(yyvsp[-1].Token).boolval==true?"TRUE":"FALSE");
				else
					yyerror("print error");
				if((yyvsp[-1].Token).tokentype==0||(yyvsp[-1].Token).tokentype==4)
					fprintf(javacode,"\t\tinvokevirtual void java.io.PrintStream.print(int)\n");
				else
					fprintf(javacode,"\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
			  }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 735 "hw2.y" /* yacc.c:1646  */
    {
				statecount = 1;
				if((yyvsp[-2].Token).tokentype==0)
					printf("%d",(yyvsp[-2].Token).intval);
				else if((yyvsp[-2].Token).tokentype==1)
					printf("%f",(yyvsp[-2].Token).floatval);
				else if((yyvsp[-2].Token).tokentype==3)
					printf("%s",(yyvsp[-2].Token).stringval);
				else if((yyvsp[-2].Token).tokentype==4)
					printf("%s",(yyvsp[-2].Token).boolval==true?"TRUE":"FALSE");
				else
					yyerror("print error");
				if((yyvsp[-2].Token).tokentype==0||(yyvsp[-2].Token).tokentype==4)
					fprintf(javacode,"\t\tinvokevirtual void java.io.PrintStream.print(int)\n");
				else
					fprintf(javacode,"\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
			  }
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 753 "hw2.y" /* yacc.c:1646  */
    {statecount = 0;tabcount++;createtab(tabcount);}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 754 "hw2.y" /* yacc.c:1646  */
    {cout<<endl;dump(tabcount);tabcount--; Trace("<'{' scopecontent reduce to block >\n");}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 756 "hw2.y" /* yacc.c:1646  */
    {if(is_const!=1)fprintf(javacode,"\t\tldc \"%s\"\n",(yyvsp[0].Token).stringval);(yyval.Token).tokentype=3;strcpy((yyval.Token).stringval,(yyvsp[0].Token).stringval);Trace("< string_expression reduce to expression >\n");}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 757 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=4;(yyval.Token).boolval = (yyvsp[0].Token).boolval;Trace("< bool_expression reduce to expression >\n");}
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 759 "hw2.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype=0;
				(yyval.Token).intval = (yyvsp[-2].Token).intval+(yyvsp[0].Token).intval;
				fprintf(javacode,"\t\tiadd\n");
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype=1;
				(yyval.Token).floatval = (yyvsp[-2].Token).floatval+(yyvsp[0].Token).intval;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				(yyval.Token).tokentype=1;
				(yyval.Token).floatval = (yyvsp[-2].Token).intval+(yyvsp[0].Token).floatval;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				(yyval.Token).tokentype = 1;
				(yyval.Token).floatval = (yyvsp[-2].Token).floatval+(yyvsp[0].Token).floatval;
			}
			else
				yyerror("type error");
			Trace("< expression '+' expression reduce to expression >\n");
		}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 786 "hw2.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype=0;
				(yyval.Token).intval = (yyvsp[-2].Token).intval-(yyvsp[0].Token).intval;
				fprintf(javacode,"\t\tisub\n");
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype=1;
				(yyval.Token).floatval = (yyvsp[-2].Token).floatval-(yyvsp[0].Token).intval;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				(yyval.Token).tokentype=1;
				(yyval.Token).floatval = (yyvsp[-2].Token).intval-(yyvsp[0].Token).floatval;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				(yyval.Token).tokentype = 1;
				(yyval.Token).floatval = (yyvsp[-2].Token).floatval-(yyvsp[0].Token).floatval;
			}
			else
				yyerror("type error");
			Trace("< expression '-' expression reduce to expression >\n");
		}
#line 2590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 813 "hw2.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype=0;
				(yyval.Token).intval = (yyvsp[-2].Token).intval*(yyvsp[0].Token).intval;
				fprintf(javacode,"\t\timul\n");
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype=1;
				(yyval.Token).floatval = (yyvsp[-2].Token).floatval*(yyvsp[0].Token).intval;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				(yyval.Token).tokentype=1;
				(yyval.Token).floatval = (yyvsp[-2].Token).intval*(yyvsp[0].Token).floatval;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				(yyval.Token).tokentype = 1;
				(yyval.Token).floatval = (yyvsp[-2].Token).floatval*(yyvsp[0].Token).floatval;
			}
			else
				yyerror("type error");
			Trace("< expression '*' expression reduce to expression >\n");
		}
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 840 "hw2.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype=0;
				(yyval.Token).intval = (yyvsp[-2].Token).intval/(yyvsp[0].Token).intval;
				fprintf(javacode,"\t\tidiv\n");
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype=1;
				(yyval.Token).floatval = (yyvsp[-2].Token).floatval/(yyvsp[0].Token).intval;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				(yyval.Token).tokentype=1;
				(yyval.Token).floatval = (yyvsp[-2].Token).intval/(yyvsp[0].Token).floatval;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				(yyval.Token).tokentype = 1;
				(yyval.Token).floatval = (yyvsp[-2].Token).floatval/(yyvsp[0].Token).floatval;
			}
			else
				yyerror("type error");
			Trace("< expression '/' expression reduce to expression >\n");
		}
#line 2652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 867 "hw2.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype = 0;
				(yyval.Token).intval = (yyvsp[-2].Token).intval % (yyvsp[0].Token).intval;
				fprintf(javacode,"\t\tirem\n");
			}
			else
				yyerror("type error");
			Trace("< expression '%%' expression >\n");
		}
#line 2668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 879 "hw2.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].Token).tokentype==0)
			{
				(yyval.Token).tokentype=0;
				(yyval.Token).intval = -(yyvsp[0].Token).intval;
				fprintf(javacode,"\t\tineg\n");
			}
			else if((yyvsp[0].Token).tokentype==1)
			{
				(yyval.Token).tokentype=1;
				(yyval.Token).floatval = -(yyvsp[0].Token).floatval;
			}
			else
				yyerror("type error");
			Trace("< '-' expression reduce to expression >\n");
		}
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 896 "hw2.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].Token).tokentype==0)
			{
				(yyval.Token).tokentype = 0;
				(yyval.Token).intval = (yyvsp[-1].Token).intval;
			}
			else if((yyvsp[-1].Token).tokentype==1)
			{
				(yyval.Token).tokentype = 1;
				(yyval.Token).floatval = (yyvsp[-1].Token).floatval;
			}
			else if((yyvsp[-1].Token).tokentype==3)
			{
				(yyval.Token).tokentype = 3;
				(yyval.Token).stringval = (yyvsp[-1].Token).stringval;
			}
			else if((yyvsp[-1].Token).tokentype==4)
			{
				(yyval.Token).tokentype = 4;
				(yyval.Token).boolval = (yyvsp[-1].Token).boolval;
			}
			else
				yyerror("type error");
			Trace("< '(' expression ')' reduce to expression >\n");
		}
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 922 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).intval = (yyvsp[0].Token).intval;
			(yyval.Token).tokentype=0;
			if(is_local==1)					// to check it must be under these condictions , I can print the context under this in jasm
				if(is_const!=1)
					fprintf(javacode,"\t\tsipush %d\n",(yyvsp[0].Token).intval);
			Trace("< INTEGER reduce to expression >\n");
		}
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 930 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).floatval = (yyvsp[0].Token).floatval;(yyval.Token).tokentype=1; Trace("< FLOAT reduce to expression >\n");}
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 932 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype = returntype(tabcount,(yyvsp[0].Token).stringval);
			if(returntype(tabcount,(yyvsp[0].Token).stringval)==0)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,(yyvsp[0].Token).stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				(yyval.Token).intval = thetab[choose][index].theint;
				symtab tempsym = returnsymbol((yyvsp[0].Token).stringval);
				if(tempsym.is_global==1)
					fprintf(javacode,"\t\tgetstatic int proj3.%s\n",(yyvsp[0].Token).stringval);
				else
				{
					if(tempsym.thestate==1)
						fprintf(javacode,"\t\tiload %d\n",tempsym.stackindex);
					else
						fprintf(javacode,"\t\tsipush %d\n",tempsym.theint);
				}
					
			}
			else if(returntype(tabcount,(yyvsp[0].Token).stringval)==1)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,(yyvsp[0].Token).stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				(yyval.Token).floatval = thetab[choose][index].thefloat;
			}
			else if(returntype(tabcount,(yyvsp[0].Token).stringval)==3)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,(yyvsp[0].Token).stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				strcpy((yyval.Token).stringval,thetab[choose][index].thestring.c_str());
			}
			else if(returntype(tabcount,(yyvsp[0].Token).stringval)==4)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,(yyvsp[0].Token).stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				(yyval.Token).boolval = thetab[choose][index].thebool;
				symtab tempsym = returnsymbol((yyvsp[0].Token).stringval);
				if(tempsym.is_global==1)
					fprintf(javacode,"\t\tgetstatic bool proj3.%s\n",(yyvsp[0].Token).stringval);
				else
				{
					if(tempsym.thestate==1)
						fprintf(javacode,"\t\tiload %d\n",tempsym.stackindex);
					else
						fprintf(javacode,"\t\ticonst_%d\n",tempsym.thebool);
				}
			}
			else
				yyerror("type error");
			Trace("< NAME reduce to expression >\n");
		}
#line 2822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1012 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype = returntype(tabcount,(yyvsp[-3].Token).stringval);
			if(returntype(tabcount,(yyvsp[-3].Token).stringval)==0)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,(yyvsp[-3].Token).stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				(yyval.Token).intval = thetab[choose][index].int_array[(yyvsp[-1].Token).intval];
			}
			else if(returntype(tabcount,(yyvsp[-3].Token).stringval)==1)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,(yyvsp[-3].Token).stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				(yyval.Token).floatval = thetab[choose][index].float_array[(yyvsp[-1].Token).intval];
			}
			else if(returntype(tabcount,(yyvsp[-3].Token).stringval)==3)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,(yyvsp[-3].Token).stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				strcpy((yyval.Token).stringval,thetab[choose][index].string_array[(yyvsp[-1].Token).intval].c_str());
			}
			else if(returntype(tabcount,(yyvsp[-3].Token).stringval)==4)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,(yyvsp[-3].Token).stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				(yyval.Token).boolval = thetab[choose][index].bool_array[(yyvsp[-1].Token).intval];
			}
			else
				yyerror("type error");
			Trace("< NAME '[' int_expression ']' reduce to expression >\n");
		}
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1071 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=3;strcpy((yyval.Token).stringval,(yyvsp[0].Token).stringval);Trace("< \" STRING \" reduce to string_expression >\n");}
#line 2891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1073 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval+(yyvsp[0].Token).intval;Trace("< int_expression '+' int_expression reduce to int_expression >\n");}
#line 2897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1074 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval-(yyvsp[0].Token).intval;Trace("< int_expression '-' int_expression reduce to int_expression >\n");}
#line 2903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1075 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval*(yyvsp[0].Token).intval;Trace("< int_expression '*' int_expression reduce to int_expression >\n");}
#line 2909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1076 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval/(yyvsp[0].Token).intval;Trace("< int_expression '/' int_expression reduce to int_expression >\n");}
#line 2915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1077 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval%(yyvsp[0].Token).intval;Trace("< int_expression '%%' int_expression reduce to int_expression >\n");}
#line 2921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1078 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=-(yyvsp[0].Token).intval;Trace("< '-' int_expression reduce to int_expression >\n");}
#line 2927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1079 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-1].Token).intval;Trace("< '(' int_expression ')' reduce to int_expression >\n");}
#line 2933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1080 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[0].Token).intval;Trace("< INTEGER reduce to int_expression >\n");}
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1082 "hw2.y" /* yacc.c:1646  */
    {
		if(returntype(tabcount,(yyvsp[0].Token).stringval)!=0)
			yyerror("type error");
		else{
			(yyval.Token).tokentype=0;
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,(yyvsp[0].Token).stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			(yyval.Token).intval = thetab[choose][index].theint;
		}
		Trace("< NAME reduce to int_expression >\n");
	}
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1102 "hw2.y" /* yacc.c:1646  */
    {
				  label_stack[label_top++] = label_counter; // to prevent if block has other ifs , i must save the else or outside label
				  fprintf(javacode,"\t\tifeq L%d\n",label_counter); // if bool_expression is not,it will jump to else or outside
				  label_counter+=2;  // to prevent if block has other ifs, label+1 -> outside label , label+2 -> for next if or anothe condiction
			  }
#line 2972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1107 "hw2.y" /* yacc.c:1646  */
    {Trace("< IF '(' bool_expression ')' else_statement reduce to if_statement >\n");}
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1109 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 2984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1110 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 2990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1112 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-1]+1);  // go outside
				  	fprintf(javacode,"\tL%d:\n",label_stack[label_top-1]);
				}
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1116 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 3005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1118 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-1]+1);  // go outside
				  	fprintf(javacode,"\tL%d:\n",label_stack[label_top-1]);
				}
#line 3014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1122 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 3020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1124 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-1]+1);  // go outside
				  	fprintf(javacode,"\tL%d:\n",label_stack[label_top-1]);
				}
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1128 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 3035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1130 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-1]+1);  // go outside
				  	fprintf(javacode,"\tL%d:\n",label_stack[label_top-1]);
				}
#line 3044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1134 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 3050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1137 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype=4;
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).intval==(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifeq L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).intval==(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).floatval==(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).floatval==(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==3&&(yyvsp[0].Token).tokentype==3)
			{
				if(strcmp((yyvsp[-2].Token).stringval,(yyvsp[0].Token).stringval)==0)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==4&&(yyvsp[0].Token).tokentype==4)
			{
				if((yyvsp[-2].Token).boolval==(yyvsp[0].Token).boolval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifeq L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else
				yyerror("type error");
			Trace("expression EQ expression reduce to bool_expression\n");
		}
#line 3117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1200 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype=4;
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).intval>=(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifge L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).intval>=(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).floatval>=(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).floatval>=(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==4&&(yyvsp[0].Token).tokentype==4)
			{
				if((yyvsp[-2].Token).boolval>=(yyvsp[0].Token).boolval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifge L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else
				yyerror("type error");
			Trace("< expression GE expression reduce to bool_expression >\n");
		}
#line 3177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1256 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype=4;
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).intval<=(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifle L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).intval<=(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).floatval<=(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).floatval<=(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==4&&(yyvsp[0].Token).tokentype==4)
			{
				if((yyvsp[-2].Token).boolval<=(yyvsp[0].Token).boolval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifle L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else
				yyerror("type error");
			Trace("< expression LE expression reduce to bool_expression >\n");
		}
#line 3237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1312 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype=4;
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).intval!=(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifne L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).intval!=(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).floatval!=(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).floatval!=(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==3&&(yyvsp[0].Token).tokentype==3)
			{
				if(strcmp((yyvsp[-2].Token).stringval,(yyvsp[0].Token).stringval)!=0)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==4&&(yyvsp[0].Token).tokentype==4)
			{
				if((yyvsp[-2].Token).boolval!=(yyvsp[0].Token).boolval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifne L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else
				yyerror("type error");
			Trace("< expression NE expression reduce to bool_expression >\n");
		}
#line 3304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1375 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype=4;
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).intval>(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifgt L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).intval>(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).floatval>(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).floatval>(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==4&&(yyvsp[0].Token).tokentype==4)
			{
				if((yyvsp[-2].Token).boolval>(yyvsp[0].Token).boolval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tifgt L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else
				yyerror("type error");
			Trace("< expression '>' expression reduce to bool_expression >\n");
		}
#line 3364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1431 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype=4;
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).intval<(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tiflt L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).intval<(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).floatval<(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).floatval<(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==4&&(yyvsp[0].Token).tokentype==4)
			{
				if((yyvsp[-2].Token).boolval<(yyvsp[0].Token).boolval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tisub\n");
				fprintf(javacode,"\t\tiflt L%d\n",label_counter);
				fprintf(javacode,"\t\ticonst_0\n");
				fprintf(javacode,"\t\tgoto L%d\n",label_counter+1);
				fprintf(javacode,"\tL%d:\n\t\ticonst_1\n",label_counter);
				fprintf(javacode,"\tL%d:\n",label_counter+1);
				label_counter+=2;
			}
			else
				yyerror("type error");
			Trace("< expression '<' expression reduce to bool_expression >\n");
		}
#line 3424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1487 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype=4;
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).intval&&(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tiand\n");
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).intval&&(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).floatval&&(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).floatval&&(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==4&&(yyvsp[0].Token).tokentype==4)
			{
				if((yyvsp[-2].Token).boolval&&(yyvsp[0].Token).boolval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tiand\n");
			}
			else
				yyerror("type error");
			Trace("< expression AND expression reduce to bool_expression >\n");
		}
#line 3472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1531 "hw2.y" /* yacc.c:1646  */
    {
			(yyval.Token).tokentype=4;
			if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).intval||(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tior\n");
			}
			else if((yyvsp[-2].Token).tokentype==0&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).intval||(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==0)
			{
				if((yyvsp[-2].Token).floatval||(yyvsp[0].Token).intval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==1&&(yyvsp[0].Token).tokentype==1)
			{
				if((yyvsp[-2].Token).floatval||(yyvsp[0].Token).floatval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			else if((yyvsp[-2].Token).tokentype==4&&(yyvsp[0].Token).tokentype==4)
			{
				if((yyvsp[-2].Token).boolval||(yyvsp[0].Token).boolval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
				fprintf(javacode,"\t\tior\n");
			}
			else
				yyerror("type error");
			Trace("< expression OR expression reduece to bool_expression >\n");
		}
#line 3520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1575 "hw2.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].Token).tokentype!=4)
				yyerror("type error");
			else{
				(yyval.Token).tokentype=4;
				if(!(yyvsp[0].Token).boolval)
					(yyval.Token).boolval = true;
				else
					(yyval.Token).boolval = false;
			}
			fprintf(javacode,"\t\tixor\n");
			Trace("< '!' expression reduce to bool_expression >\n");
		}
#line 3538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1588 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=4;(yyval.Token).boolval=true;fprintf(javacode,"\t\ticonst_1\n");Trace("< TRUE reduce to bool_expression >\n");}
#line 3544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1589 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=4;(yyval.Token).boolval=false;fprintf(javacode,"\t\ticonst_0\n");Trace("< FALSE reduce to bool_expression >\n");}
#line 3550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1592 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\tL%d:\n",label_counter);  // give the label for the start of while
					label_stack[label_top++] = label_counter;   // to keep the start label of while for prevent the many whiles
					label_counter++;
				}
#line 3560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1598 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tifeq L%d\n",label_counter);
					label_stack[label_top++] = label_counter;   // to keep the end label of while for prevent the many whiles
					label_counter++;
				}
#line 3570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1603 "hw2.y" /* yacc.c:1646  */
    {Trace("< WHILE '(' bool_expression ')' while_content reduce to loop_statement >\n");}
#line 3576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1606 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-2]);  // go to the near start of while , label_top-1 -> end of while , label_top-2 ->start of while
					fprintf(javacode,"\tL%d:\n",label_stack[--label_top]);  // for print the end label of while
					label_top--;  // delete the inside while to become the outside while
					Trace("< block '}' reduece to while_content >\n");
				}
#line 3587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1613 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-2]);  // go to the near start of while , label_top-1 -> end of while , label_top-2 ->start of while
					fprintf(javacode,"\tL%d:\n",label_stack[--label_top]);  // for print the end label of while
					label_top--;  // delete the inside while to become the outside while
					Trace("< WHILE statement reduce to while_content >\n");
				}
#line 3598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1620 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;Trace("< INT reduce to Type >\n");}
#line 3604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1621 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=1;Trace("< FLOAT reduce to Type >\n");}
#line 3610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1622 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=3;Trace("< STR reduce to Type >\n");}
#line 3616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1623 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=4;Trace("< BOOL reduce to Type >\n");}
#line 3622 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3626 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1625 "hw2.y" /* yacc.c:1906  */

//#include "lex.yy.c"
int main()
{
    thetab[0] = (symtab*)malloc(sizeof(symtab)*256);
	javacode = fopen("B10415040.jasm","w");
	fprintf(javacode,"class proj3\n{\n");
    /* open the source program file */
    /*if (argc != 2) {
	printf ("Usage: sc filename\n");
	exit(1);
    }*/
    //yyin = fopen(argv[1], "r");         /* open input file */
    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
	yyerror("Parsing error !");     /* syntax error */
	fprintf(javacode,"}");
	fclose(javacode);
    return 0;
}
void createtab(int tabcount)										// under this is to process the symbol table;
{
	thetab[tabcount] = (symtab*)malloc(sizeof(symtab)*256);
}
symtab returnsymbol(char *id)
{
	int choose = 0;
	int index = 0;
	for(int i =0;i<totalargu;i++)    // second to find the arguments
	{
		if(argu[i].name.compare(id)==0)
			return argu[i];
	}
	for(int i =tabcount;i>=0;i--)    // first to find local variable
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			return thetab[choose][index];
	}
	yyerror("No this variable");
}
void dump(int tabcount)
{
	cout<<"the symbol table: "<<endl;
	for(int i =0;i<idcount[tabcount];i++)
	{
		if(thetab[tabcount][i].array_or_not==0)
		{
			cout<<thetab[tabcount][i].name<<'\t';
			if(thetab[tabcount][i].thetype==0)
			{
				cout<<thetab[tabcount][i].theint<<'\t';
				if(thetab[tabcount][i].thestate==0)
					cout<<"const"<<'\t';
				else
					cout<<"variable"<<'\t';
				cout<<"int"<<endl;
			}
			else if(thetab[tabcount][i].thetype==1)
			{
				cout<<thetab[tabcount][i].thefloat<<'\t';
				if(thetab[tabcount][i].thestate==0)
					cout<<"const"<<'\t';
				else
					cout<<"variable"<<'\t';
				cout<<"float"<<endl;
			}
			else if(thetab[tabcount][i].thetype==3)
			{
				cout<<thetab[tabcount][i].thestring<<'\t';
				if(thetab[tabcount][i].thestate==0)
					cout<<"const"<<'\t';
				else
					cout<<"variable"<<'\t';
				cout<<"string"<<endl;
			}
			else if(thetab[tabcount][i].thetype==4)
			{
				cout<<thetab[tabcount][i].thebool<<'\t';
				if(thetab[tabcount][i].thestate==0)
					cout<<"const"<<'\t';
				else
					cout<<"variable"<<'\t';
				cout<<"bool"<<endl;
			}
		}
		else
		{
			if(thetab[tabcount][i].thetype==0)
			{
				for(int j =0;j<thetab[tabcount][i].array_count;j++)
				{
					cout<<thetab[tabcount][i].name<<"["<<j<<"]"<<'\t';
					cout<<thetab[tabcount][i].int_array[j]<<'\t';
					cout<<"variable"<<'\t';
					cout<<"int"<<endl;
				}
			}
			else if(thetab[tabcount][i].thetype==1)
			{
				for(int j =0;j<thetab[tabcount][i].array_count;j++)
				{
					cout<<thetab[tabcount][i].name<<"["<<j<<"]"<<'\t';
					cout<<thetab[tabcount][i].float_array[j]<<'\t';
					cout<<"variable"<<'\t';
					cout<<"float"<<endl;
				}
			}
			else if(thetab[tabcount][i].thetype==3)
			{
				for(int j =0;j<thetab[tabcount][i].array_count;j++)
				{
					cout<<thetab[tabcount][i].name<<"["<<j<<"]"<<'\t';
					cout<<thetab[tabcount][i].string_array[j]<<'\t';
					cout<<"variable"<<'\t';
					cout<<"string"<<endl;
				}
			}
			else if(thetab[tabcount][i].thetype==4)
			{
				for(int j =0;j<thetab[tabcount][i].array_count;j++)
				{
					cout<<thetab[tabcount][i].name<<"["<<j<<"]"<<'\t';
					cout<<thetab[tabcount][i].bool_array[j]<<'\t';
					cout<<"variable"<<'\t';
					cout<<"bool"<<endl;
				}
			}
		}
	}
	cout<<endl;
	idcount[tabcount]=0;
	free(thetab[tabcount]);
}
void argudump()
{
	cout<<endl<<"the argument table: "<<endl;
	for(int i =0;i<totalargu;i++)
	{
		cout<<argu[i].name<<'\t';
		if(argu[i].thetype==0)
			cout<<"int"<<'\t'<<endl;
		else if(argu[i].thetype==1)
			cout<<"float"<<'\t'<<endl;
		else if(argu[i].thetype==3)
			cout<<"string"<<'\t'<<endl;
		else if(argu[i].thetype==4)
			cout<<"bool"<<'\t'<<endl;
	}
	cout<<endl;
	free(argu);
	totalargu =0;
}
void functiondump()
{
	cout<<"the total function table: "<<endl;
	for(int i =0;i<functioncount;i++)
	{
		cout<<funtab[i].name<<'\t';
		if(funtab[i].thetype==0)
			cout<<funtab[i].theint<<'\t';
		else if(funtab[i].thetype==1)
			cout<<funtab[i].thefloat<<'\t';
		else if(funtab[i].thetype==3)
			cout<<funtab[i].thestring<<'\t';
		else if(funtab[i].thetype==4)
			cout<<funtab[i].thebool<<'\t';
		else if(funtab[i].thetype==5)
			cout<<funtab[i].theint<<'\t';
		cout<<"function"<<'\t';
		if(funtab[i].thetype==0)
			cout<<"int"<<'\t'<<endl;
		else if(funtab[i].thetype==1)
			cout<<"float"<<'\t'<<endl;
		else if(funtab[i].thetype==3)
			cout<<"string"<<'\t'<<endl;
		else if(funtab[i].thetype==4)
			cout<<"bool"<<'\t'<<endl;
		else if(funtab[i].thetype==5)
			cout<<"void"<<'\t'<<endl;
		cout<<endl;
	}
}
void insert(int tabcount,char *id,int check,int array_check)
{
	int index = returnindex(tabcount,id);
	if(index==-1)
	{
		int push = idcount[tabcount];
		if(tabcount==0)
			thetab[tabcount][push].is_global = 1;
		else
			thetab[tabcount][push].is_global = 0;
		thetab[tabcount][push].name=id;
		if(check==1)
			thetab[tabcount][push].stackindex = stackcount;
		thetab[tabcount][push].thestate = check;
		thetab[tabcount][push].array_or_not = array_check;
		idcount[tabcount]++;
		if(check==1)
			stackcount++;
	}
	else
	{
		if(thetab[tabcount][index].thestate==0)
			yyerror("constant error");
		else
		{
			if(returntype(tabcount,id)==0)
			{
				if(tabcount==0)
					thetab[tabcount][index].is_global = 1;
				else
					thetab[tabcount][index].is_global = 0;
				thetab[tabcount][index].thetype = 0;
				thetab[tabcount][index].theint = 0;
			}
			else if(returntype(tabcount,id)==1)
			{
				if(tabcount==0)
					thetab[tabcount][index].is_global = 1;
				else
					thetab[tabcount][index].is_global = 0;
				thetab[tabcount][index].thetype = 1;
				thetab[tabcount][index].thefloat = 0;
			}
			else if(returntype(tabcount,id)==3)
			{
				if(tabcount==0)
					thetab[tabcount][index].is_global = 1;
				else
					thetab[tabcount][index].is_global = 0;
				thetab[tabcount][index].thetype = 3;
				thetab[tabcount][index].thestring="___";
			}
			else if(returntype(tabcount,id)==4)
			{
				if(tabcount==0)
					thetab[tabcount][index].is_global = 1;
				else
					thetab[tabcount][index].is_global = 0;
				thetab[tabcount][index].thetype = 4;
				thetab[tabcount][index].thefloat = true;
			}
		}
	}
}
void insert(int tabcount,char *id,int type,int check,int array_check)
{
	int index = returnindex(tabcount,id);
	if(index==-1)
	{
		int push = idcount[tabcount];
		if(tabcount==0)
			thetab[tabcount][push].is_global = 1;
		else
			thetab[tabcount][push].is_global = 0;
		thetab[tabcount][push].name=id;
		if(check==1)
			thetab[tabcount][push].stackindex = stackcount;
		thetab[tabcount][push].thetype = type;
		thetab[tabcount][push].thestate = check;
		thetab[tabcount][push].array_or_not = array_check;
		idcount[tabcount]++;
		if(check==1)
			stackcount++;
	}
	else
	{
		if(thetab[tabcount][index].thestate==0)
			yyerror("constant error");
		else
		{
			if(returntype(tabcount,id)==0)
			{
				if(tabcount==0)
					thetab[tabcount][index].is_global = 1;
				else
					thetab[tabcount][index].is_global = 0;
				thetab[tabcount][index].thetype = type;
				thetab[tabcount][index].theint = 0;
			}
			else if(returntype(tabcount,id)==1)
			{
				if(tabcount==0)
					thetab[tabcount][index].is_global = 1;
				else
					thetab[tabcount][index].is_global = 0;
				thetab[tabcount][index].thetype = type;
				thetab[tabcount][index].thefloat = 0;
			}
			else if(returntype(tabcount,id)==3)
			{
				if(tabcount==0)
					thetab[tabcount][index].is_global = 1;
				else
					thetab[tabcount][index].is_global = 0;
				thetab[tabcount][index].thetype = type;
				thetab[tabcount][index].thestring = "___";
			}
			else if(returntype(tabcount,id)==4)
			{
				if(tabcount==0)
					thetab[tabcount][index].is_global = 1;
				else
					thetab[tabcount][index].is_global = 0;
				thetab[tabcount][index].thetype = type;
				thetab[tabcount][index].thefloat = true;
			}
		}
	}
}
void insertargu(string id,int type)
{
	argu[totalargu].name = id;
	argu[totalargu].thetype = type;
	argu[totalargu].stackindex = stackcount;
	argu[totalargu].thestate = 1;
	argu[totalargu].is_global = 0;
	totalargu++;
	stackcount++;
}
void insertfunction(char *id,int type)
{
	int push = functioncount;
	funtab[push].name = id;
	funtab[push].thetype = type;
	funtab[push].function_content = temp_content;
	functioncount++;
	if(type==0)
		funtab[push].theint = 0;
	else if(type==1)
	 	funtab[push].thefloat =0.0;
	else if(type==3)
		funtab[push].thestring = "___";
	else if(type==4)
	 	funtab[push].thebool =false;
	else if(type==5)
	{
		funtab[push].theint = 0;
	}
	else
		yyerror("type error");
}
int returnindex(int tabcount,char *id)
{
	for(int i =0;i<idcount[tabcount];i++)
	{
		if(thetab[tabcount][i].name.compare(id)==0)
			return i;
	}
	return -1;
}
int returntype(int tabcount,char *id)
{
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
	}
	return thetab[choose][index].thetype;
}
int returnfunctiontype(char *id)
{
	int choose =0;
	for(int i =0;i<functioncount;i++)
	{
		if(funtab[i].name.compare(id)==0)
		{
			choose = i;
			break;
		}
		if(i==functioncount-1)
			yyerror("function not in function table error");
	}
	return funtab[choose].thetype;
}
symtab returnfunctiontable(char *id)
{
	for(int i =0;i<functioncount;i++)
	{
		if(funtab[i].name.compare(id)==0)
			return funtab[i];
	}
}
int return_constant_or_variable(int tabcount,char *id)
{
	for(int i =0;i<totalargu;i++)
	{
		if(argu[i].name.compare(id)==0)
			return 1;
	}
	cout<<456<<endl;
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
		if(i==0)
			yyerror("not in symbol table error");
	}
	return thetab[choose][index].thestate;
}
int insertcheck(int tabcount,char *id)
{
	for(int i =0;i<totalargu;i++)
	{
		if(argu[i].name.compare(id)==0)
			return 1;
	}
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
		if(i==0)
			yyerror("not in symbol table error");
	}
	if(thetab[choose][index].thestate==0)
		yyerror("constant error");
	else
		return 1;
}
void insertvalue(int tabcount,char *id,int temp)
{
	for(int i =0;i<totalargu;i++)
	{
		if(argu[i].name.compare(id)==0)
		{
			argu[i].theint = temp;
			return;
		}
	}
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
		if(i==0)
			yyerror("not in symbol table error");
	}
	thetab[choose][index].theint = temp;
	thetab[choose][index].thetype = 0;
}
void insertvalue(int tabcount,char *id,float temp)
{
	for(int i =0;i<totalargu;i++)
	{
		if(argu[i].name.compare(id)==0)
		{
			argu[i].thefloat = temp;
			return;
		}
	}
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
		if(i==0)
			yyerror("not in symbol table error");
	}
	thetab[choose][index].thefloat = temp;
	thetab[choose][index].thetype = 1;
}
void insertvalue(int tabcount,char *id,char *temp)
{
	for(int i =0;i<totalargu;i++)
	{
		if(argu[i].name.compare(id)==0)
		{
			argu[i].thestring = temp;
			return;
		}
	}
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
		if(i==0)
			yyerror("not in symbol table error");
	}
	thetab[choose][index].thestring=temp;
	thetab[choose][index].thetype = 3;
}
void insertvalue(int tabcount,char *id,bool temp)
{
	for(int i =0;i<totalargu;i++)
	{
		if(argu[i].name.compare(id)==0)
		{
			argu[i].thebool = temp;
			return;
		}
	}
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
		if(i==0)
			yyerror("not in symbol table error");
	}
	thetab[choose][index].thebool = temp;
	thetab[choose][index].thetype = 4;
}
void insertarray(int tabcount,char *id,int Type,int size,int array_check,const char *theblank)
{
	int index = returnindex(tabcount,id);
	if(index==-1)
	{
		int push = idcount[tabcount];
		thetab[tabcount][push].name = id;
		thetab[tabcount][push].thetype = Type;
		thetab[tabcount][push].array_or_not = array_check;
		if(Type==0)
		{
			thetab[tabcount][push].int_array = (int*)malloc(sizeof(int)*size);
			thetab[tabcount][push].array_count = size;
			idcount[tabcount]++;
		}
		else if(Type==1)
		{
			thetab[tabcount][push].float_array = (float*)malloc(sizeof(float)*size);
			thetab[tabcount][push].array_count = size;
			idcount[tabcount]++;
		}
		else if(Type==3)
		{
			thetab[tabcount][push].string_array = (string*)malloc(sizeof(string)*size);
			thetab[tabcount][push].array_count = size;
			idcount[tabcount]++;
		}
		else if(Type==4)
		{
			thetab[tabcount][push].bool_array = (bool*)malloc(sizeof(bool)*size);
			thetab[tabcount][push].array_count = size;
			idcount[tabcount]++;
		}
	}
	else
	{
		thetab[tabcount][index].name = id;
		thetab[tabcount][index].thetype = Type;
		thetab[tabcount][index].array_or_not = array_check;
		if(Type==0)
		{
			thetab[tabcount][index].int_array = (int*)malloc(sizeof(int)*size);
			thetab[tabcount][index].array_count = size;
			idcount[tabcount]++;
		}
		else if(Type==1)
		{
			thetab[tabcount][index].float_array = (float*)malloc(sizeof(float)*size);
			thetab[tabcount][index].array_count = size;
			idcount[tabcount]++;
		}
		else if(Type==3)
		{
			thetab[tabcount][index].string_array = (string*)malloc(sizeof(string)*size);
			thetab[tabcount][index].array_count = size;
			idcount[tabcount]++;
		}
		else if(Type==4)
		{
			thetab[tabcount][index].bool_array = (bool*)malloc(sizeof(bool)*size);
			thetab[tabcount][index].array_count = size;
			idcount[tabcount]++;
		}
	}
}
void insertarrayvalue(int tabcount,char *id,int position,int temp)
{
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
	}
	thetab[choose][index].int_array[position] = temp;
}
void insertarrayvalue(int tabcount,char *id,int position,float temp)
{
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
	}
	thetab[choose][index].float_array[position] = temp;
}
void insertarrayvalue(int tabcount,char *id,int position,char *temp)
{
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
	}
	thetab[choose][index].string_array[position]=temp;
}
void insertarrayvalue(int tabcount,char *id,int position,bool temp)
{
	int choose = 0;
	int index = 0;
	for(int i =tabcount;i>=0;i--)
	{
		index = returnindex(i,id);
		choose = i;
		if(index!=-1)
			break;
	}
	thetab[choose][index].bool_array[position] = temp;
}
int yyerror(const char *msg)
{
    printf("%s\n", msg);
	exit(0);
    return 0;
}
