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
#line 1 "hw2.y" /* yacc.c:339  */

    #include<iostream>
    #include<string>
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    using namespace std;
	FILE *javacode;
    #define Trace(t) printf(t)
    typedef  struct {									// declare the symbol table type and its member;
		string name;
		string function_content;     // for function_invoke's name and argument type
		int is_global; 				// 0:local 1:global
		int stackindex; 			// the symbol in stack number
		int thestate; 				// 0:constant 1:variable
		int array_or_not; 			// 0:not array 1:array
		int thetype; 				// 0:int 1:float 2:char 3:string 4:bool
		int array_count;
			int theint;
			float thefloat;
			string thestring;
			bool thebool;
			int *int_array;
			float *float_array;
			string *string_array;
			bool *bool_array;
    }symtab;
	typedef struct{
		string name;
		int thetype;
		int stackindex;
	}symargu;
	symtab *argu;
	int totalargu = 0;
    symtab *thetab[256];
    symtab funtab[256];
    int idcount[256]={0};
    int functioncount = 0;
	int functionstatetype = 5;
    int tabcount = 0;
	int statecount =0;
	int stackcount = 0;
	int label_stack[100];   // for the situation has many if-else whiles,so i must save the next else's or outside label
	int label_top = 1;      // the label_stack pointer,points the stack top,the top-1 is the newest label
	int label_counter = 0;  // the total label
	int is_const = 0;       // avoid declare const print ipush
	int is_local = 0;		// avoid declare global variable print ipush
    string temp_content="";    // the temp for the function content
	void createtab(int tabcount);
	symtab returnsymbol(char *id);
    void dump(int tabcount);
	void argudump();
	void functiondump();
    void insert(int tabcount,char *id,int check,int array_check);
	void insert(int tabcount,char *id,int type,int check,int array_check);
	void insertargu(string id,int type);
    void insertfunction(char *id,int type);
    int returnindex(int tabcount,char *id);
    int returntype(int tabcount,char *id);
	int return_constant_or_variable(int tabcount,char *id);
    int returnfunctiontype(char *id);
	symtab returnfunctiontable(char *id);
    int insertcheck(int tabcount,char *id);
    void insertvalue(int tabcount,char *id,int temp);
    void insertvalue(int tabcount,char *id,float temp);
    void insertvalue(int tabcount,char *id,char *temp);
    void insertvalue(int tabcount,char *id,bool temp);
    void insertarray(int tabcount,char *id,int Type,int size,int array_check,const char *theblank);
    void insertarrayvalue(int tabcount,char *id,int position,int temp);
    void insertarrayvalue(int tabcount,char *id,int position,float temp);
    void insertarrayvalue(int tabcount,char *id,int position,char *temp);
    void insertarrayvalue(int tabcount,char *id,int position,bool temp);
    extern "C" {
	    int yyerror(const char *msg);
	    int yylex();
    }
    //FILE *yyin;

#line 145 "y.tab.c" /* yacc.c:339  */

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
#line 80 "hw2.y" /* yacc.c:355  */

	struct{
		int tokentype; //0:int 1:float 2:char 3:string 4:bool
		union{
			int intval;
			float floatval;
			char* stringval;
			bool boolval;
		};
	}Token;

#line 297 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 314 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   468

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
      64,    65,    54,    52,    67,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    59,
      51,    61,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    68,     2,     2,     2,     2,
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
       0,   113,   113,   115,   116,   118,   119,   121,   122,   124,
     125,   126,   128,   129,   130,   131,   132,   134,   134,   137,
     184,   218,   243,   244,   246,   245,   251,   250,   274,   273,
     299,   317,   336,   336,   361,   361,   387,   424,   461,   468,
     481,   499,   517,   535,   553,   554,   555,   556,   558,   559,
     561,   562,   563,   590,   617,   644,   671,   683,   700,   726,
     727,   728,   808,   869,   868,   876,   877,   879,   878,   885,
     884,   891,   890,   897,   896,   903,   966,  1022,  1078,  1141,
    1197,  1253,  1297,  1341,  1354,  1355,  1358,  1364,  1357,  1371,
    1378,  1386,  1387,  1388,  1389,  1391,  1393,  1394,  1395,  1396,
    1397,  1398,  1399,  1400,  1401,  1421,  1454,  1485,  1484,  1523,
    1522,  1537,  1536,  1572,  1571,  1593,  1594,  1595,  1596,  1598,
    1600,  1601
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
  "UMINUS", "';'", "'{'", "'='", "'['", "']'", "'('", "')'", "':'", "','",
  "'}'", "$accept", "start", "program", "function_dec", "declarations",
  "declaration", "scopecontent", "block", "$@1", "statement", "$@2", "$@3",
  "$@4", "print_content", "constant", "$@5", "$@6", "variable", "array",
  "return", "expression", "if_statement", "$@7", "else_statement", "$@8",
  "$@9", "$@10", "$@11", "bool_expression", "loop_statement", "$@12",
  "$@13", "while_content", "Type", "string_expression", "int_expression",
  "function_return", "function", "$@14", "$@15", "$@16", "$@17",
  "function_block", "arguments", "argument", "function_invoke", YY_NULLPTR
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
      62,    60,    43,    45,    42,    47,    37,    33,   305,    59,
     123,    61,    91,    93,    40,    41,    58,    44,   125
};
# endif

#define YYPACT_NINF -197

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-197)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,   -41,   -19,    17,  -197,  -197,    22,    24,     2,    27,
      40,    22,    19,    50,   -34,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,    39,    82,  -197,    11,    47,    64,    58,    57,
      48,    99,    11,    48,  -197,  -197,  -197,  -197,    70,    11,
      89,    95,    96,   131,  -197,  -197,  -197,  -197,   120,  -197,
      48,    48,    48,   319,  -197,  -197,   116,   117,   130,   132,
     143,   319,  -197,  -197,    11,  -197,   -24,  -197,   155,    95,
    -197,    87,  -197,  -197,   157,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,   112,   113,
     217,   241,    48,    48,  -197,   123,    48,  -197,   147,    11,
    -197,  -197,  -197,    87,    87,   359,  -197,   410,   410,   410,
     410,   349,   340,   410,   410,   108,   108,  -197,  -197,  -197,
     151,   371,   156,   376,   158,   388,   162,   393,   319,   319,
      95,   163,  -197,   164,  -197,    18,   123,  -197,   123,  -197,
    -197,   319,   152,  -197,  -197,   354,    87,    87,    87,    87,
      87,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,    48,    61,   172,    48,   177,    73,    87,  -197,  -197,
    -197,    95,  -197,   114,   114,  -197,  -197,  -197,   319,   161,
      48,  -197,   223,    48,   247,    48,   -29,   271,   183,   405,
    -197,  -197,   179,  -197,   201,  -197,   178,    28,  -197,  -197,
     186,    67,   189,   190,  -197,  -197,   136,   185,    48,   196,
     250,  -197,  -197,  -197,    67,    48,  -197,   295,   261,   211,
     204,  -197,  -197,  -197,  -197,   220,    95,    -7,  -197,    95,
      -7,   222,  -197,   225,  -197,  -197,  -197
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     0,     7,     0,     0,
       0,     5,     0,     0,     0,     1,     3,     8,     9,    10,
      11,     6,     0,    38,    32,     0,     0,   113,     0,   118,
       0,     0,     0,     0,    94,    92,    91,    93,     0,     0,
       0,     0,   111,     0,    85,    84,    59,    60,    61,    95,
       0,     0,     0,    36,    51,    50,     0,     0,     0,     0,
      39,    33,    34,   119,     0,    17,     0,   114,     0,     0,
     117,     0,    57,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,    16,    49,   116,     0,     0,
     112,   103,   104,     0,     0,     0,    58,    77,    76,    75,
      78,    81,    82,    79,    80,    52,    53,    54,    55,    56,
     104,     0,   104,     0,   104,     0,   104,     0,    37,    35,
       0,     0,    24,    28,    86,     0,    14,    18,    15,    22,
      23,    48,     0,   107,   101,     0,     0,     0,     0,     0,
       0,    62,    43,    47,    41,    45,    40,    44,    42,    46,
     110,     0,     0,     0,     0,     0,     0,     0,    12,    13,
     115,     0,   102,    96,    97,    98,    99,   100,     0,    51,
       0,    25,     0,     0,     0,     0,    61,     0,     0,     0,
     108,    63,     0,    30,     0,    29,    51,     0,    19,    20,
       0,     0,    58,     0,    87,   106,   121,     0,     0,     0,
      66,    64,    31,    27,     0,     0,   105,     0,    65,    73,
       0,    90,    88,   120,    21,    71,     0,     0,    89,     0,
       0,     0,    74,     0,    72,    70,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,  -197,   141,    30,  -197,    62,   -72,  -197,  -196,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
     -30,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -142,  -197,
    -197,  -197,  -197,   -26,  -197,   -79,  -197,  -197,  -197,  -197,
    -197,  -197,   -65,   245,  -197,    80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   136,     7,   137,    66,    95,   138,
     162,   163,   164,   181,     8,    33,    93,     9,    10,    98,
     178,   139,   201,   211,   229,   226,   230,   227,    54,   140,
     165,   214,   222,    38,    55,   105,   188,    11,   171,   130,
      69,    41,    67,    28,    29,   207
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    96,    13,    61,   100,   210,    60,    12,   131,   121,
     123,   125,   127,    63,    34,   132,   133,    15,   221,   179,
      72,    73,    74,    35,   144,   145,   134,    24,    36,    14,
       6,   232,    25,    71,   234,   197,     1,    17,    94,    44,
      37,   135,     2,   196,    97,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    45,    44,
       1,    18,   128,   129,     2,   160,   141,   173,   174,   175,
     176,   177,    44,   143,    46,    47,    48,    49,    45,   166,
     167,    50,   131,    22,    44,    51,    19,    26,   189,   132,
     133,    45,    52,   205,    46,    47,    48,    49,    23,    20,
     134,    50,    56,    45,    27,    51,   190,    46,    47,    48,
      49,    57,    52,    39,    50,   135,    58,    40,    51,    46,
      47,   186,    49,    42,    43,   180,    50,    65,    59,   209,
      51,    62,   182,   101,   184,   102,   187,    52,   131,    64,
     103,     2,   220,    30,    31,   132,   133,    16,    32,    68,
     192,   104,    21,   194,   231,    65,   134,   233,   101,   101,
     120,   122,    85,    86,    87,   103,   103,   206,   148,   149,
     150,   135,    75,    76,    77,    78,   104,   104,   217,    26,
      79,    80,    71,    88,    89,   206,    81,    82,    83,    84,
      85,    86,    87,    75,    76,    77,    78,    90,   168,    91,
     169,    79,    80,   215,    92,    99,   142,    81,    82,    83,
      84,    85,    86,    87,   152,    75,    76,    77,    78,   154,
     170,   156,   106,    79,    80,   158,   191,   161,   -26,    81,
      82,    83,    84,    85,    86,    87,   183,    75,    76,    77,
      78,   185,   199,   204,   202,    79,    80,   208,   212,   213,
     216,    81,    82,    83,    84,    85,    86,    87,   219,    75,
      76,    77,    78,   101,   218,   124,   203,    79,    80,   225,
     103,   -69,   228,    81,    82,    83,    84,    85,    86,    87,
     -67,   104,   193,    75,    76,    77,    78,   101,    70,   126,
     235,    79,    80,   236,   103,   223,     0,    81,    82,    83,
      84,    85,    86,    87,     0,   104,   195,    75,    76,    77,
      78,     0,     0,     0,     0,    79,    80,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,     0,     0,
     198,    75,    76,    77,    78,     0,     0,     0,     0,    79,
      80,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,     0,     0,   224,    75,    76,    77,    78,     0,
       0,     0,     0,    79,    80,     0,     0,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    75,    76,    77,    78,
       0,     0,     0,     0,    79,    75,    76,    77,    78,     0,
      81,    82,    83,    84,    85,    86,    87,     0,     0,    81,
      82,    83,    84,    85,    86,    87,   146,   147,   148,   149,
     150,   146,   147,   148,   149,   150,     0,     0,     0,   172,
       0,     0,   151,   146,   147,   148,   149,   150,   146,   147,
     148,   149,   150,     0,   153,     0,     0,     0,     0,   155,
     146,   147,   148,   149,   150,   146,   147,   148,   149,   150,
       0,   157,     0,     0,     0,     0,   159,   146,   147,   148,
     149,   150,    83,    84,    85,    86,    87,     0,   200
};

static const yytype_int16 yycheck[] =
{
      30,    25,    21,    33,    69,   201,    32,    48,    15,    88,
      89,    90,    91,    39,     3,    22,    23,     0,   214,   161,
      50,    51,    52,    12,   103,   104,    33,    61,    17,    48,
       0,   227,    66,    62,   230,    64,    14,     7,    64,    11,
      29,    48,    18,   185,    68,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    30,    11,
      14,    59,    92,    93,    18,   130,    96,   146,   147,   148,
     149,   150,    11,    99,    46,    47,    48,    49,    30,    61,
      62,    53,    15,    64,    11,    57,    59,    48,   167,    22,
      23,    30,    64,    65,    46,    47,    48,    49,    48,    59,
      33,    53,     3,    30,    65,    57,   171,    46,    47,    48,
      49,    12,    64,    66,    53,    48,    17,    53,    57,    46,
      47,    48,    49,    65,    67,    64,    53,    60,    29,   201,
      57,    61,   162,    46,   164,    48,   166,    64,    15,    50,
      53,    18,   214,    61,    62,    22,    23,     6,    66,    53,
     180,    64,    11,   183,   226,    60,    33,   229,    46,    46,
      48,    48,    54,    55,    56,    53,    53,   197,    54,    55,
      56,    48,    36,    37,    38,    39,    64,    64,   208,    48,
      44,    45,    62,    67,    67,   215,    50,    51,    52,    53,
      54,    55,    56,    36,    37,    38,    39,    67,   136,    67,
     138,    44,    45,    67,    61,    50,    59,    50,    51,    52,
      53,    54,    55,    56,    63,    36,    37,    38,    39,    63,
      68,    63,    65,    44,    45,    63,    65,    64,    64,    50,
      51,    52,    53,    54,    55,    56,    64,    36,    37,    38,
      39,    64,    59,    65,    65,    44,    45,    61,    59,    59,
      65,    50,    51,    52,    53,    54,    55,    56,     8,    36,
      37,    38,    39,    46,    68,    48,    65,    44,    45,     8,
      53,    60,    68,    50,    51,    52,    53,    54,    55,    56,
      60,    64,    59,    36,    37,    38,    39,    46,    43,    48,
      68,    44,    45,    68,    53,   215,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    64,    59,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      59,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    59,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    44,    36,    37,    38,    39,    -1,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    52,    53,    54,    55,
      56,    52,    53,    54,    55,    56,    -1,    -1,    -1,    65,
      -1,    -1,    63,    52,    53,    54,    55,    56,    52,    53,
      54,    55,    56,    -1,    63,    -1,    -1,    -1,    -1,    63,
      52,    53,    54,    55,    56,    52,    53,    54,    55,    56,
      -1,    63,    -1,    -1,    -1,    -1,    63,    52,    53,    54,
      55,    56,    52,    53,    54,    55,    56,    -1,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    18,    70,    71,    72,    73,    74,    83,    86,
      87,   106,    48,    21,    48,     0,    72,    73,    59,    59,
      59,    72,    64,    48,    61,    66,    48,    65,   112,   113,
      61,    62,    66,    84,     3,    12,    17,    29,   102,    66,
      53,   110,    65,    67,    11,    30,    46,    47,    48,    49,
      53,    57,    64,    89,    97,   103,     3,    12,    17,    29,
     102,    89,    61,   102,    50,    60,    76,   111,    53,   109,
     112,    62,    89,    89,    89,    36,    37,    38,    39,    44,
      45,    50,    51,    52,    53,    54,    55,    56,    67,    67,
      67,    67,    61,    85,   102,    77,    25,    68,    88,    50,
     111,    46,    48,    53,    64,   104,    65,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      48,   104,    48,   104,    48,   104,    48,   104,    89,    89,
     108,    15,    22,    23,    33,    48,    73,    75,    78,    90,
      98,    89,    59,   102,   104,   104,    52,    53,    54,    55,
      56,    63,    63,    63,    63,    63,    63,    63,    63,    63,
     111,    64,    79,    80,    81,    99,    61,    62,    75,    75,
      68,   107,    65,   104,   104,   104,   104,   104,    89,    97,
      64,    82,    89,    64,    89,    64,    48,    89,   105,   104,
     111,    65,    89,    59,    89,    59,    97,    64,    59,    59,
      63,    91,    65,    65,    65,    65,    89,   114,    61,    76,
      78,    92,    59,    59,   100,    67,    65,    89,    68,     8,
      76,    78,   101,   114,    59,     8,    94,    96,    68,    93,
      95,    76,    78,    76,    78,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    75,    75,    75,    75,    75,    77,    76,    78,
      78,    78,    78,    78,    79,    78,    80,    78,    81,    78,
      82,    82,    84,    83,    85,    83,    86,    86,    86,    86,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    91,    90,    92,    92,    93,    92,    94,
      92,    95,    92,    96,    92,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    99,   100,    98,   101,
     101,   102,   102,   102,   102,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   105,   105,   107,   106,   108,
     106,   109,   106,   110,   106,   111,   111,   112,   112,   113,
     114,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     2,     2,
       2,     2,     2,     2,     1,     1,     0,     0,     3,     4,
       4,     7,     1,     1,     0,     3,     0,     6,     0,     4,
       2,     4,     0,     5,     0,     7,     5,     7,     3,     5,
       8,     8,     8,     8,     8,     8,     8,     8,     2,     1,
       1,     1,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     4,     0,     6,     2,     1,     0,     6,     0,
       5,     0,     5,     0,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     0,     0,     7,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     4,     3,     0,    10,     0,
       9,     0,     7,     0,     6,     4,     2,     3,     1,     3,
       3,     1
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
#line 113 "hw2.y" /* yacc.c:1646  */
    {if(functioncount==0)yyerror("no function error");cout<<endl<<"global ";dump(tabcount);cout<<endl<<"global ";functiondump();Trace("< program reduce to start >\n");}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 115 "hw2.y" /* yacc.c:1646  */
    {Trace("< declarations function_dec reduce to program >\n");}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 116 "hw2.y" /* yacc.c:1646  */
    {Trace("< function_dec reduce to program >\n");}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 118 "hw2.y" /* yacc.c:1646  */
    {Trace("< function reduce to function_dec >\n");}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 119 "hw2.y" /* yacc.c:1646  */
    {Trace("< function function_dec reduce to function_dec >\n");}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 121 "hw2.y" /* yacc.c:1646  */
    {Trace("< declaration reduce to declarations >\n");}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 122 "hw2.y" /* yacc.c:1646  */
    {Trace("< declaration declarations reduce to declarations >\n");}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 124 "hw2.y" /* yacc.c:1646  */
    {Trace("< constant reduce to declaration >\n");}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 125 "hw2.y" /* yacc.c:1646  */
    {Trace("< variable reduce to declaration >\n");}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 126 "hw2.y" /* yacc.c:1646  */
    {Trace("< array reduce to declaration >\n");}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "hw2.y" /* yacc.c:1646  */
    {Trace("< declarations scopecontent reduce to scopecontent >\n");}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "hw2.y" /* yacc.c:1646  */
    {Trace("< statement scopecontent reduce to scopecontent >\n");}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 130 "hw2.y" /* yacc.c:1646  */
    {Trace("< declarations reduce to scopecontent >\n");}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 131 "hw2.y" /* yacc.c:1646  */
    {Trace("< statement reduce to scopecontent >\n");}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 132 "hw2.y" /* yacc.c:1646  */
    {Trace("< empty reduce to scopecontent >\n");}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "hw2.y" /* yacc.c:1646  */
    {statecount = 0;tabcount++;createtab(tabcount);}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 135 "hw2.y" /* yacc.c:1646  */
    {cout<<endl;dump(tabcount);tabcount--; Trace("<'{' scopecontent '}' reduce to block >\n");}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 138 "hw2.y" /* yacc.c:1646  */
    {
			statecount = 1;
			if(insertcheck(tabcount,(yyvsp[-3].Token).stringval)==1)
			{
				if((yyvsp[-1].Token).tokentype==0&&returntype(tabcount,(yyvsp[-3].Token).stringval)==0)
				{
					insertvalue(tabcount,(yyvsp[-3].Token).stringval,(yyvsp[-1].Token).intval);
					symtab tempsym = returnsymbol((yyvsp[-3].Token).stringval);
					if(tempsym.is_global==1)
						fprintf(javacode,"\t\tputstatic int proj3.%s\n",(yyvsp[-3].Token).stringval);
					else
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
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 185 "hw2.y" /* yacc.c:1646  */
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
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 219 "hw2.y" /* yacc.c:1646  */
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
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 243 "hw2.y" /* yacc.c:1646  */
    {statecount = 1;Trace("< if_statement reduce to statement >\n");}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 244 "hw2.y" /* yacc.c:1646  */
    {statecount = 1;Trace("< loop_statement reduce to statement >\n");}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 246 "hw2.y" /* yacc.c:1646  */
    {
			fprintf(javacode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 249 "hw2.y" /* yacc.c:1646  */
    {Trace("< PRINT expression reduce to statement >\n");}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 251 "hw2.y" /* yacc.c:1646  */
    {
			fprintf(javacode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 255 "hw2.y" /* yacc.c:1646  */
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
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 274 "hw2.y" /* yacc.c:1646  */
    {
			fprintf(javacode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 278 "hw2.y" /* yacc.c:1646  */
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
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 300 "hw2.y" /* yacc.c:1646  */
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
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 318 "hw2.y" /* yacc.c:1646  */
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
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 336 "hw2.y" /* yacc.c:1646  */
    {is_const=1;}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 338 "hw2.y" /* yacc.c:1646  */
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
			is_const=0;
			Trace("< LET NAME '=' expression reduece to constant >\n");
		}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 361 "hw2.y" /* yacc.c:1646  */
    {is_const = 1;}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 363 "hw2.y" /* yacc.c:1646  */
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
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 388 "hw2.y" /* yacc.c:1646  */
    {
			insert(tabcount,(yyvsp[-2].Token).stringval,1,0);
			if((yyvsp[0].Token).tokentype==0)
			{
				insertvalue(tabcount,(yyvsp[-2].Token).stringval,(yyvsp[0].Token).intval);
				if(tabcount==0)
					fprintf(javacode,"\tfield static int %s = %d\n",(yyvsp[-2].Token).stringval,(yyvsp[0].Token).intval);
				else
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
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 425 "hw2.y" /* yacc.c:1646  */
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
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 462 "hw2.y" /* yacc.c:1646  */
    {
			insert(tabcount,(yyvsp[0].Token).stringval,1,0);
			if(tabcount==0)
					fprintf(javacode,"\tfield static int %s\n",(yyvsp[0].Token).stringval);
			Trace("< LET MUT NAME reduce to variable >\n");
		}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 469 "hw2.y" /* yacc.c:1646  */
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
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 482 "hw2.y" /* yacc.c:1646  */
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
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 500 "hw2.y" /* yacc.c:1646  */
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
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 518 "hw2.y" /* yacc.c:1646  */
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
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 536 "hw2.y" /* yacc.c:1646  */
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
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 553 "hw2.y" /* yacc.c:1646  */
    {insertarray(tabcount,(yyvsp[-5].Token).stringval,0,(yyvsp[-1].Token).intval,1,"___"); Trace("< LET MUT NAME '[' INT ',' int_expression ']' reduce to array >\n");}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 554 "hw2.y" /* yacc.c:1646  */
    {insertarray(tabcount,(yyvsp[-5].Token).stringval,1,(yyvsp[-1].Token).intval,1,"___"); Trace("< LET MUT NAME '[' FLOAT ',' int_expression ']' reduce to array >\n");}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 555 "hw2.y" /* yacc.c:1646  */
    {insertarray(tabcount,(yyvsp[-5].Token).stringval,3,(yyvsp[-1].Token).intval,1,"___"); Trace("< LET MUT NAME '[' STR ',' int_expression ']' reduce to array >\n");}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 556 "hw2.y" /* yacc.c:1646  */
    {insertarray(tabcount,(yyvsp[-5].Token).stringval,4,(yyvsp[-1].Token).intval,1,"___"); Trace("< LET MUT NAME '[' BOOL ',' int_expression ']' reduce to array >\n");}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 558 "hw2.y" /* yacc.c:1646  */
    {if(functionstatetype!=5)fprintf(javacode,"\t\tireturn\n\t}\n");else fprintf(javacode,"\t\treturn\n\t}\n");Trace("< RETURN expression reduce to return >\n");}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 559 "hw2.y" /* yacc.c:1646  */
    {if(functionstatetype!=5)fprintf(javacode,"\t\tireturn\n\t}\n");else fprintf(javacode,"\t\treturn\n\t}\n");Trace("< RETURN reduce to return >\n");}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 561 "hw2.y" /* yacc.c:1646  */
    {if(is_const!=1)fprintf(javacode,"\t\tldc \"%s\"\n",(yyvsp[0].Token).stringval);(yyval.Token).tokentype=3;strcpy((yyval.Token).stringval,(yyvsp[0].Token).stringval);Trace("< string_expression reduce to expression >\n");}
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 562 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=4;(yyval.Token).boolval = (yyvsp[0].Token).boolval;Trace("< bool_expression reduce to expression >\n");}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 564 "hw2.y" /* yacc.c:1646  */
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
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 591 "hw2.y" /* yacc.c:1646  */
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
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 618 "hw2.y" /* yacc.c:1646  */
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
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 645 "hw2.y" /* yacc.c:1646  */
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
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 672 "hw2.y" /* yacc.c:1646  */
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
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 684 "hw2.y" /* yacc.c:1646  */
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
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 701 "hw2.y" /* yacc.c:1646  */
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
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 726 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).intval = (yyvsp[0].Token).intval;(yyval.Token).tokentype=0;if(is_local==1)if(is_const!=1)fprintf(javacode,"\t\tsipush %d\n",(yyvsp[0].Token).intval); Trace("< INTEGER reduce to expression >\n");}
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 727 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).floatval = (yyvsp[0].Token).floatval;(yyval.Token).tokentype=1; Trace("< FLOAT reduce to expression >\n");}
#line 2467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 729 "hw2.y" /* yacc.c:1646  */
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
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 809 "hw2.y" /* yacc.c:1646  */
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
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 869 "hw2.y" /* yacc.c:1646  */
    {
				  label_stack[label_top++] = label_counter; // to prevent if block has other ifs , i must save the else or outside label
				  fprintf(javacode,"\t\tifeq L%d\n",label_counter); // if bool_expression is not,it will jump to else or outside
				  label_counter+=2;  // to prevent if block has other ifs, label+1 -> outside label , label+2 -> for next if or anothe condiction
			  }
#line 2624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 874 "hw2.y" /* yacc.c:1646  */
    {Trace("< IF '(' bool_expression ')' else_statement reduce to if_statement >\n");}
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 876 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 877 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 879 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-1]+1);  // go outside
				  	fprintf(javacode,"\tL%d:\n",label_stack[label_top-1]);
				}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 883 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 885 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-1]+1);  // go outside
				  	fprintf(javacode,"\tL%d:\n",label_stack[label_top-1]);
				}
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 889 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 891 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-1]+1);  // go outside
				  	fprintf(javacode,"\tL%d:\n",label_stack[label_top-1]);
				}
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 895 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 2687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 897 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-1]+1);  // go outside
				  	fprintf(javacode,"\tL%d:\n",label_stack[label_top-1]);
				}
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 901 "hw2.y" /* yacc.c:1646  */
    {fprintf(javacode,"\tL%d:\n",label_stack[--label_top]+1);}
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 904 "hw2.y" /* yacc.c:1646  */
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
#line 2769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 967 "hw2.y" /* yacc.c:1646  */
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
#line 2829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1023 "hw2.y" /* yacc.c:1646  */
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
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1079 "hw2.y" /* yacc.c:1646  */
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
#line 2956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1142 "hw2.y" /* yacc.c:1646  */
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
#line 3016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1198 "hw2.y" /* yacc.c:1646  */
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
#line 3076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1254 "hw2.y" /* yacc.c:1646  */
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
#line 3124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1298 "hw2.y" /* yacc.c:1646  */
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
#line 3172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1342 "hw2.y" /* yacc.c:1646  */
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
			Trace("< '!' expression reduce to bool_expression >\n");
		}
#line 3189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1354 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=4;(yyval.Token).boolval=true;fprintf(javacode,"\t\tsipush %d\n",1);Trace("< TRUE reduce to bool_expression >\n");}
#line 3195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1355 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=4;(yyval.Token).boolval=false;fprintf(javacode,"\t\tsipush %d\n",0);Trace("< FALSE reduce to bool_expression >\n");}
#line 3201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1358 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\tL%d:\n",label_counter);  // give the label for the start of while
					label_stack[label_top++] = label_counter;   // to keep the start label of while for prevent the many whiles
					label_counter++;
				}
#line 3211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1364 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tifeq L%d\n",label_counter);
					label_stack[label_top++] = label_counter;   // to keep the end label of while for prevent the many whiles
					label_counter++;
				}
#line 3221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1369 "hw2.y" /* yacc.c:1646  */
    {Trace("< WHILE '(' bool_expression ')' while_content reduce to loop_statement >\n");}
#line 3227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1372 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-2]);  // go to the near start of while , label_top-1 -> end of while , label_top-2 ->start of while
					fprintf(javacode,"\tL%d:\n",label_stack[--label_top]);  // for print the end label of while
					label_top--;  // delete the inside while to become the outside while
					Trace("< WHILE '(' bool_expression ')' block reduece to loop_statement >\n");
				}
#line 3238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1379 "hw2.y" /* yacc.c:1646  */
    {
					fprintf(javacode,"\t\tgoto L%d\n",label_stack[label_top-2]);  // go to the near start of while , label_top-1 -> end of while , label_top-2 ->start of while
					fprintf(javacode,"\tL%d:\n",label_stack[--label_top]);  // for print the end label of while
					label_top--;  // delete the inside while to become the outside while
					Trace("< WHILE '(' bool_expression ')' statement reduce to loop_statement >\n");
				}
#line 3249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1386 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;Trace("< INT reduce to Type >\n");}
#line 3255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1387 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=1;Trace("< FLOAT reduce to Type >\n");}
#line 3261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1388 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=3;Trace("< STR reduce to Type >\n");}
#line 3267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1389 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=4;Trace("< BOOL reduce to Type >\n");}
#line 3273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1391 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=3;strcpy((yyval.Token).stringval,(yyvsp[0].Token).stringval);Trace("< \" STRING \" reduce to string_expression >\n");}
#line 3279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1393 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval+(yyvsp[0].Token).intval;Trace("< int_expression '+' int_expression reduce to int_expression >\n");}
#line 3285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1394 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval-(yyvsp[0].Token).intval;Trace("< int_expression '-' int_expression reduce to int_expression >\n");}
#line 3291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1395 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval*(yyvsp[0].Token).intval;Trace("< int_expression '*' int_expression reduce to int_expression >\n");}
#line 3297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1396 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval/(yyvsp[0].Token).intval;Trace("< int_expression '/' int_expression reduce to int_expression >\n");}
#line 3303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1397 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-2].Token).intval%(yyvsp[0].Token).intval;Trace("< int_expression '%%' int_expression reduce to int_expression >\n");}
#line 3309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1398 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=-(yyvsp[0].Token).intval;Trace("< '-' int_expression reduce to int_expression >\n");}
#line 3315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1399 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[-1].Token).intval;Trace("< '(' int_expression ')' reduce to int_expression >\n");}
#line 3321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1400 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).tokentype=0;(yyval.Token).intval=(yyvsp[0].Token).intval;Trace("< INTEGER reduce to int_expression >\n");}
#line 3327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1402 "hw2.y" /* yacc.c:1646  */
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
#line 3350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1422 "hw2.y" /* yacc.c:1646  */
    {
		int check = returnfunctiontype((yyvsp[-3].Token).stringval);
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
			yyerror("type error");
		symtab tempfunction = returnfunctiontable((yyvsp[-3].Token).stringval);
		if(tempfunction.thetype==0)
			fprintf(javacode,"\t\tinvokestatic int proj3.%s(%s\n",(yyvsp[-3].Token).stringval,tempfunction.function_content.c_str());
		else if(tempfunction.thetype==4)
			fprintf(javacode,"\t\tinvokestatic bool proj3.%s(%s\n",(yyvsp[-3].Token).stringval,tempfunction.function_content.c_str());
		Trace("< NAME '(' argument ')' reduce to function_return >\n");
	}
#line 3387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1455 "hw2.y" /* yacc.c:1646  */
    {
		int check = returnfunctiontype((yyvsp[-2].Token).stringval);
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
			yyerror("type error");
		fprintf(javacode,"\t\tinvokestatic %d proj3.%s()\n",returnfunctiontype((yyvsp[-2].Token).stringval),(yyvsp[-2].Token).stringval);
		Trace("NAME '(' ')' reduce to function_return >\n");
	}
#line 3420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1485 "hw2.y" /* yacc.c:1646  */
    {
			is_local = 1;
			functionstatetype = (yyvsp[0].Token).tokentype;
			if((yyvsp[0].Token).tokentype==0)
				fprintf(javacode,"\tmethod public static int %s(",(yyvsp[-6].Token).stringval);
			else if((yyvsp[0].Token).tokentype==4)
				fprintf(javacode,"\tmethod public static int %s(",(yyvsp[-6].Token).stringval);
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
			insertfunction((yyvsp[-6].Token).stringval,(yyvsp[0].Token).tokentype);
			temp_content="";
			fprintf(javacode,"\tmax_stack 15\n");
			fprintf(javacode,"\tmax_locals 15\n");
			fprintf(javacode,"\t{\n");
		  }
#line 3461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1521 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).stringval=(yyvsp[-8].Token).stringval;argudump();Trace("< FN NAME '(' argument ')' '-' '>' Type block reduce to function >\n");}
#line 3467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1523 "hw2.y" /* yacc.c:1646  */
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
#line 3484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1535 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).stringval=(yyvsp[-7].Token).stringval;Trace("< FN NAME '(' ')' '-' '>' Type block reduce to function >\n");}
#line 3490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1537 "hw2.y" /* yacc.c:1646  */
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
#line 3528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1570 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).stringval=(yyvsp[-5].Token).stringval;argudump();Trace("< FN NAME '(' argument ')' block reduce to function >\n");}
#line 3534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1572 "hw2.y" /* yacc.c:1646  */
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
#line 3558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1591 "hw2.y" /* yacc.c:1646  */
    {(yyval.Token).stringval=(yyvsp[-4].Token).stringval;Trace("< FN NAME '(' ')' block reduce to function >\n");}
#line 3564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1593 "hw2.y" /* yacc.c:1646  */
    {is_local = 0;stackcount=0;Trace("< block return ';' '}' reduce to function_block >\n");}
#line 3570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1594 "hw2.y" /* yacc.c:1646  */
    {is_local = 0;if(statecount==0)yyerror("no statement error");fprintf(javacode,"\t\treturn\n\t}\n");stackcount=0;Trace("< block '}' reduce to function_block >\n");}
#line 3576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1595 "hw2.y" /* yacc.c:1646  */
    {Trace("< argument ',' arguments reduce to arguments >\n");}
#line 3582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1596 "hw2.y" /* yacc.c:1646  */
    {Trace("< argument reduce to arguments >\n");}
#line 3588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1598 "hw2.y" /* yacc.c:1646  */
    {if(totalargu==0){stackcount=0;argu = (symtab*)malloc(sizeof(symtab)*10);}insertargu((yyvsp[-2].Token).stringval,(yyvsp[0].Token).tokentype); Trace("< NAME ':' Type reduce to argument >\n");}
#line 3594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1600 "hw2.y" /* yacc.c:1646  */
    {Trace("< expression ',' function_invoke reduce to function_invoke >\n");}
#line 3600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1601 "hw2.y" /* yacc.c:1646  */
    {Trace("< expression reduce to function_invoke >\n");}
#line 3606 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3610 "y.tab.c" /* yacc.c:1646  */
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
#line 1603 "hw2.y" /* yacc.c:1906  */

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
