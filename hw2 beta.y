%{
    #include<iostream>
    #include<string>
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    using namespace std;
    #define Trace(t) printf(t)
    typedef  struct {									// declare the symbol table type and its member;
		string name;
		int thestate; //0:constant 1:variable
		int array_or_not; //0:not array 1:array
		int thetype; //0:int 1:float 2:char 3:string 4:bool
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
	}symargu;
	symargu *argu;
	int totalargu = 0;
    symtab *thetab[256];
    symtab funtab[256];
    int idcount[256]={0};
    int functioncount = 0;
    int tabcount = 0;
	int statecount =0;
    void createtab(int tabcount);
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
%}

%union{
	struct{
		int tokentype; //0:int 1:float 2:char 3:string 4:bool
		union{
			int intval;
			float floatval;
			char* stringval;
			bool boolval;
		};
	}Token;
}
%token BOOL BREAK CHAR CONTINUE DO ELSE ENUM EXTERN FALSE FLOAT FOR FN IF IN INT LET LOOP MATCH MUT PRINT PRINTLN
%token PUB RETURN SELF STATIC STRUCT STR TRUE USE WHERE WHILE
%token PLUS_PLUS MINUS_MINUS LE GE EQ NE PLUS_EQ MINUS_EQ MUL_EQ DIV_EQ AND OR
%token <Token>INTEGER
%token <Token>Float
%token <Token>NAME
%token <Token>STRING
%type <Token> bool_expression int_expression
%type <Token> string_expression
%type <Token> start program statement constant variable array return expression if_statement loop_statement Type function argument function_return function_dec declarations declaration scopecontent block
%start start

%left OR 
%left AND 
%left '>' '<' GE EQ LE NE
%left '+' '-'
%left '*' '/' '%'
%right '!'
%right UMINUS

%%
// !!!!! init values are 0 and " " and false;
start: program 					{if(functioncount==0)yyerror("no function error");cout<<endl<<"global ";dump(tabcount);cout<<endl<<"global ";functiondump();Trace("< program reduce to start >\n");}		// the start to program
	;
program: declarations function_dec         	{Trace("< declarations function_dec reduce to program >\n");}    		// some simple statements
	|  	 function_dec    					{Trace("< function_dec reduce to program >\n");}   // some simple statements
	;
function_dec: 	function					{Trace("< function reduce to function_dec >\n");}
			| 	function function_dec		{Trace("< function function_dec reduce to function_dec >\n");}
			;
declarations:	declaration					{Trace("< declaration reduce to declarations >\n");}
			|	declaration declarations	{Trace("< declaration declarations reduce to declarations >\n");}
		;
declaration:   constant ';'         {Trace("< constant reduce to declaration >\n");}		// the simple statement constant ex: let a = 10; reduce to statement;
			|  variable ';'         {Trace("< variable reduce to declaration >\n");}		// the simple statement variable ex: let mut a = 10; reduce to statement;
			|  array ';'            {Trace("< array reduce to declaration >\n");}			// the simple statement array ex: let mut a[int,10]; reduce to statement;
			;
scopecontent:	declarations scopecontent			{Trace("< declarations scopecontent reduce to scopecontent >\n");}
			|	statement scopecontent				{Trace("< statement scopecontent reduce to scopecontent >\n");}
			|	declarations						{Trace("< declarations reduce to scopecontent >\n");}
			|	statement							{Trace("< statement reduce to scopecontent >\n");}
			|	%empty								{Trace("< empty reduce to scopecontent >\n");}
			;
block:	'{'							{statecount = 0;tabcount++;createtab(tabcount);}
		scopecontent '}'			{if(statecount==0)yyerror("no statement error");cout<<endl;dump(tabcount);tabcount--; Trace("<'{' scopecontent '}' reduce to block >\n");}
		;
statement: NAME '=' expression ';'													// the simple statement ex: a = 10; reduce to statement;
		{
			statecount = 1;
			if(insertcheck(tabcount,$1.stringval)==1)
			{
				if($3.tokentype==0&&returntype(tabcount,$1.stringval)==0)
					insertvalue(tabcount,$1.stringval,$3.intval);
				else if($3.tokentype==1&&returntype(tabcount,$1.stringval)==0)
				{
					int x = $3.floatval;
					insertvalue(tabcount,$1.stringval,x);
				}
				else if($3.tokentype==4&&returntype(tabcount,$1.stringval)==0)
				{
					int x = $3.boolval;
					insertvalue(tabcount,$1.stringval,x);
				}
				else if($3.tokentype==0&&returntype(tabcount,$1.stringval)==1)
				{
					float x = $3.intval;
					insertvalue(tabcount,$1.stringval,x);
				}
				else if($3.tokentype==1&&returntype(tabcount,$1.stringval)==1)
					insertvalue(tabcount,$1.stringval,$3.floatval);
				else if($3.tokentype==3&&returntype(tabcount,$1.stringval)==3)
					insertvalue(tabcount,$1.stringval,$3.stringval);
				else if($3.tokentype==4&&returntype(tabcount,$1.stringval)==4)
					insertvalue(tabcount,$1.stringval,$3.boolval);
				else
					yyerror("assign error");
				Trace("< NAME '=' expression reduce to statement >\n");
			}
		}
		|  NAME '=' function_return ';'							// the simple statements ex: a = add(10,20); redice to statement; and make this function's return init value = 0 or "" or false
		{
			statecount = 1;
			if(insertcheck(tabcount,$1.stringval)==1)
			{
				if($3.tokentype==0)
					insertvalue(tabcount,$1.stringval,$3.intval);
				else if($3.tokentype==1)
					insertvalue(tabcount,$1.stringval,$3.floatval);
				else if($3.tokentype==3)
					insertvalue(tabcount,$1.stringval,$3.stringval);
				else if($3.tokentype==4)
					insertvalue(tabcount,$1.stringval,$3.boolval);
				else
					yyerror("assign error");
				Trace("< NAME '=' function_return reduce to statement >\n");
			}
		}
		//|  constant ';'         {Trace("< constant reduce to statement >\n");}		// the simple statement constant ex: let a = 10; reduce to statement;
		//|  variable ';'         {Trace("< variable reduce to statement >\n");}		// the simple statement variable ex: let mut a = 10; reduce to statement;
		//|  array ';'            {Trace("< array reduce to statement >\n");}			// the simple statement array ex: let mut a[int,10]; reduce to statement;
		//|  function             {Trace("< function reduce to statement >\n");}		// the simple statement function ex: fn main() { reduce to statement;
		|  NAME '[' int_expression ']' '=' expression ';'							// the simple statement array assign ex: a[0] = 10; reduce to statement;
		{
			statecount = 1;
			if($6.tokentype==0&&returntype(tabcount,$1.stringval)==0)
				insertarrayvalue(tabcount,$1.stringval,$3.intval,$6.intval);
			else if($6.tokentype==0&&returntype(tabcount,$1.stringval)==1)
			{
				float temp = $6.intval;
				insertarrayvalue(tabcount,$1.stringval,$3.intval,temp);
			}
			else if($6.tokentype==1&&returntype(tabcount,$1.stringval)==0)
			{
				int temp = $6.floatval;
				insertarrayvalue(tabcount,$1.stringval,$3.intval,temp);
			}
			else if($6.tokentype==1&&returntype(tabcount,$1.stringval)==1)
				insertarrayvalue(tabcount,$1.stringval,$3.intval,$6.floatval);
			else if($6.tokentype==3&&returntype(tabcount,$1.stringval)==3)
				insertarrayvalue(tabcount,$1.stringval,$3.intval,$6.stringval);
			else if($6.tokentype==4&&returntype(tabcount,$1.stringval)==4)
				insertarrayvalue(tabcount,$1.stringval,$3.intval,$6.boolval);
			else
					yyerror("assign error");
			Trace("< NAME '[' int_expression ']' '=' expression reduce to statement >\n");
		}
		|  if_statement         {statecount = 1;Trace("< if_statement reduce to statement >\n");}		// the simple statement if ex: if(a==10) { reduce to statement;
		|  loop_statement       {statecount = 1;Trace("< loop_statement reduce to statement >\n");}	// the simple statement loop ex: while(a==10) { reduce to statement;
		|  PRINT expression ';'							// the simple statement print ex: print "Hello world"; reduece to statement;
		{
			statecount = 1;
			if($2.tokentype==0)
				printf("%d",$2.intval);
			else if($2.tokentype==1)
				printf("%f",$2.floatval);
			else if($2.tokentype==3)
				printf("%s",$2.stringval);
			else if($2.tokentype==4)
				printf("%s",$2.boolval==true?"TRUE":"FALSE");
			else
					yyerror("print error");
			Trace("< PRINT expression reduce to statement >\n");
		}
		|  PRINT '(' expression ')' ';'					// the simple statement ex: print ("Hello world"); reduce to statement;
		{
			statecount = 1;
			if($3.tokentype==0)
				printf("%d",$3.intval);
			else if($3.tokentype==1)
				printf("%f",$3.floatval);
			else if($3.tokentype==3)
				printf("%s",$3.stringval);
			else if($3.tokentype==4)
				printf("%s",$3.boolval==true?"TRUE":"FALSE");
			else
				yyerror("print error");
			Trace("< PRINT '(' expression ')' reduce to statement >\n");
		}
		|  PRINTLN '(' expression ')' ';'				// the simple statement ex: println ("Hello world"); reduce to statement;
		{
			statecount = 1;
			if($3.tokentype==0)
				printf("%d\n",$3.intval);
			else if($3.tokentype==1)
				printf("%f\n",$3.floatval);
			else if($3.tokentype==3)
				printf("%s\n",$3.stringval);
			else if($3.tokentype==4)
				printf("%s\n",$3.boolval==true?"TRUE":"FALSE");
			else
				yyerror("println error");
			Trace("< PRINT '(' expression ')' reduce to statement >\n");
		}
		|  PRINTLN expression ';'						// the simple statement ex: println "Hello world"; reduce to statement;
		{
			statecount = 1;
			if($2.tokentype==0)
				printf("%d\n",$2.intval);
			else if($2.tokentype==1)
				printf("%f\n",$2.floatval);
			else if($2.tokentype==3)
				printf("%s\n",$2.stringval);
			else if($2.tokentype==4)
				printf("%s\n",$2.boolval==true?"TRUE":"FALSE");
			else
				yyerror("println error");
			Trace("< PRINTLN expression reduce to statement >\n");
		}
		|  return ';'   {statecount = 1;Trace("< return reduce to statement >\n");}		// the simple statement ex: return a; reduce to statement;
		//|  lscope statement      {statecount=0;Trace("< lscope reduce to statement >\n");}		// the simple statement lscope ex: { reduce to statement;
		//|  rscope       {if(statecount==0)yyerror("no statement error");Trace("< rscope reduce to statement >\n");}		// the simple statement rscope ex: } reduce to statement;
		;
constant: LET NAME '=' expression						// the declare constant ex: let a = 10 reduce to constant;
		{
			insert(tabcount,$2.stringval,0,0);
			if($4.tokentype==0)
			{
				insertvalue(tabcount,$2.stringval,$4.intval);
			}
			else if($4.tokentype==1)
			{
				insertvalue(tabcount,$2.stringval,$4.floatval);
			}
			else if($4.tokentype==3)
			{
				insertvalue(tabcount,$2.stringval,$4.stringval);
			}
			else if($4.tokentype==4)
			{
				insertvalue(tabcount,$2.stringval,$4.boolval);
			}
			else
				yyerror("assign error");
			Trace("< LET NAME '=' expression reduece to constant >\n");
		}
		| LET NAME ':' Type '=' expression				// the declare constant ex: let a : int = 10 reduce to constant;
		{
			insert(tabcount,$2.stringval,$4.tokentype,0,0);
			if($4.tokentype==0)
			{
				insertvalue(tabcount,$2.stringval,$6.intval);
			}
			else if($4.tokentype==1)
			{
				insertvalue(tabcount,$2.stringval,$6.floatval);
			}
			else if($4.tokentype==3)
			{
				insertvalue(tabcount,$2.stringval,$6.stringval);
			}
			else if($4.tokentype==4)
			{
				insertvalue(tabcount,$2.stringval,$6.boolval);
			}
			else
				yyerror("assign error");
			Trace("< LET NAME ':' Type '=' expression reduce to constant >\n");
		}
		;
variable: LET MUT NAME '=' expression					// the declare variable ex: let mut a = 10 reduce to variable;
		{
			insert(tabcount,$3.stringval,1,0);
			if($5.tokentype==0)
			{
				insertvalue(tabcount,$3.stringval,$5.intval);
			}
			else if($5.tokentype==1)
			{
				insertvalue(tabcount,$3.stringval,$5.floatval);
			}
			else if($5.tokentype==3)
			{
				insertvalue(tabcount,$3.stringval,$5.stringval);
			}
			else if($5.tokentype==4)
			{
				insertvalue(tabcount,$3.stringval,$5.boolval);
			}
			else
				yyerror("assign error");
			Trace("< LET MUT NAME '=' expression reduce to variable >\n");

		}
		| LET MUT NAME ':' Type '=' expression			// the declare variable ex: let mut a : int = 10 reduce to variable;
		{
			insert(tabcount,$3.stringval,$5.tokentype,1,0);
			if($5.tokentype==0)
			{
				insertvalue(tabcount,$3.stringval,$7.intval);
			}
			else if($5.tokentype==1)
			{
				insertvalue(tabcount,$3.stringval,$7.floatval);
			}
			else if($5.tokentype==3)
			{
				insertvalue(tabcount,$3.stringval,$7.stringval);
			}
			else if($5.tokentype==4)
			{
				insertvalue(tabcount,$3.stringval,$7.boolval);
			}
			else
				yyerror("assign error");
			Trace("< LET MUT NAME ':' Type '=' expression reduce to variable >\n");
		}
		| LET MUT NAME									// the declare variable ex: let mut a reduce to variable;
		{
			insert(tabcount,$3.stringval,1,0);
			Trace("< LET MUT NAME reduce to variable >\n");
		}
		| LET MUT NAME ':' Type							// the declare variable ex: let mut a : int reduce to variable;
		{
			insert(tabcount,$3.stringval,$5.tokentype,1,0);
			Trace("< LET MUT NAME ':' Type reduce to variable >\n");
		}
		;
array: LET MUT NAME '[' INT ',' NAME ']'				// the declare array ex: let mut a [10,b] reduce to array;
	   {
		    if(return_constant_or_variable(tabcount,$7.stringval)==1)
				yyerror("array size is variable error");
			if(returntype(tabcount,$7.stringval)!=0)
				yyerror("array size is not int error");
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,$7.stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			insertarray(tabcount,$3.stringval,0,thetab[choose][index].theint,1,"___");
			Trace("< LET MUT NAME '[' INT ',' NAME ']' reduce to array >\n");
	   }
    |  LET MUT NAME '[' FLOAT ',' NAME ']'      		// the declare array ex: let mut a[float,b] reduce to array;
	   {
		    if(return_constant_or_variable(tabcount,$7.stringval)==1)
				yyerror("array size is variable error");
			if(returntype(tabcount,$7.stringval)!=0)
				yyerror("array size is not int error");
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,$7.stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			insertarray(tabcount,$3.stringval,1,thetab[choose][index].theint,1,"___");
			Trace("< LET MUT NAME '[' FLOAT ',' NAME ']' reduce to array >\n");
	   }
	|  LET MUT NAME '[' STR ',' NAME ']'      			// the declare array ex: let mut a[str,b] reduce to array;
	   {
		    if(return_constant_or_variable(tabcount,$7.stringval)==1)
				yyerror("array size is variable error");
			if(returntype(tabcount,$7.stringval)!=0)
				yyerror("array size is not int error");
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,$7.stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			insertarray(tabcount,$3.stringval,3,thetab[choose][index].theint,1,"___");
			Trace("< LET MUT NAME '[' STRING ',' NAME ']' reduce to array >\n");
	   }
	|  LET MUT NAME '[' BOOL ',' NAME ']'      			// the declare array ex: let mut a[bool,b] reduce to array;
	   {
		    if(return_constant_or_variable(tabcount,$7.stringval)==1)
				yyerror("array size is variable error");
			if(returntype(tabcount,$7.stringval)!=0)
				yyerror("array size is not int error");
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,$7.stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			insertarray(tabcount,$3.stringval,4,thetab[choose][index].theint,1,"___");
			Trace("< LET MUT NAME '[' BOOL ',' NAME ']' reduce to array >\n");
	   }
	|  LET MUT NAME '[' INT ',' int_expression ']'      {insertarray(tabcount,$3.stringval,0,$7.intval,1,"___"); Trace("< LET MUT NAME '[' INT ',' int_expression ']' reduce to array >\n");}  // the declare array ex: let mut a[int,10] reduce to array
    |  LET MUT NAME '[' FLOAT ',' int_expression ']'    {insertarray(tabcount,$3.stringval,1,$7.intval,1,"___"); Trace("< LET MUT NAME '[' FLOAT ',' int_expression ']' reduce to array >\n");}
    |  LET MUT NAME '[' STR ',' int_expression ']'      {insertarray(tabcount,$3.stringval,3,$7.intval,1,"___"); Trace("< LET MUT NAME '[' STR ',' int_expression ']' reduce to array >\n");}
	|  LET MUT NAME '[' BOOL ',' int_expression ']'     {insertarray(tabcount,$3.stringval,4,$7.intval,1,"___"); Trace("< LET MUT NAME '[' BOOL ',' int_expression ']' reduce to array >\n");}
    ;
return: RETURN expression 	{Trace("< RETURN expression reduce to return >\n");}		// the function return ex: return 10 reduce to return;
    |   RETURN 				{Trace("< RETURN reduce to return >\n");} 					// the function return ex: return reduce to return;
    ;
expression:string_expression 	{$$.tokentype=3;strcpy($$.stringval,$1.stringval);Trace("< string_expression reduce to expression >\n");}	// the string ex: "Hello world" reduce to string_expression;
		|  bool_expression 		{$$.tokentype=4;$$.boolval = $1.boolval;Trace("< bool_expression reduce to expression >\n");}				// the bool ex: true reduce to bool_expression;
		|  expression '+' expression					// the add expression ex: 10+10 reduce to expression;
		{
			if($1.tokentype==0&&$3.tokentype==0)
			{
				$$.tokentype=0;
				$$.intval = $1.intval+$3.intval;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				$$.tokentype=1;
				$$.floatval = $1.floatval+$3.intval;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				$$.tokentype=1;
				$$.floatval = $1.intval+$3.floatval;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				$$.tokentype = 1;
				$$.floatval = $1.floatval+$3.floatval;
			}
			else
				yyerror("type error");
			Trace("< expression '+' expression reduce to expression >\n");
		}
		|  expression '-' expression					// the min expression ex: 10-10 reduce to expression;
		{
			if($1.tokentype==0&&$3.tokentype==0)
			{
				$$.tokentype=0;
				$$.intval = $1.intval-$3.intval;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				$$.tokentype=1;
				$$.floatval = $1.floatval-$3.intval;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				$$.tokentype=1;
				$$.floatval = $1.intval-$3.floatval;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				$$.tokentype = 1;
				$$.floatval = $1.floatval-$3.floatval;
			}
			else
				yyerror("type error");
			Trace("< expression '-' expression reduce to expression >\n");
		}
		|  expression '*' expression					// the mul expression ex: 10*10 reduce to expression;
		{
			if($1.tokentype==0&&$3.tokentype==0)
			{
				$$.tokentype=0;
				$$.intval = $1.intval*$3.intval;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				$$.tokentype=1;
				$$.floatval = $1.floatval*$3.intval;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				$$.tokentype=1;
				$$.floatval = $1.intval*$3.floatval;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				$$.tokentype = 1;
				$$.floatval = $1.floatval*$3.floatval;
			}
			else
				yyerror("type error");
			Trace("< expression '*' expression reduce to expression >\n");
		}
		|  expression '/' expression					// the div expression ex: 10/10 reduce to expression;
		{
			if($1.tokentype==0&&$3.tokentype==0)
			{
				$$.tokentype=0;
				$$.intval = $1.intval/$3.intval;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				$$.tokentype=1;
				$$.floatval = $1.floatval/$3.intval;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				$$.tokentype=1;
				$$.floatval = $1.intval/$3.floatval;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				$$.tokentype = 1;
				$$.floatval = $1.floatval/$3.floatval;
			}
			else
				yyerror("type error");
			Trace("< expression '/' expression reduce to expression >\n");
		}
		| expression '%' expression
		{
			if($1.tokentype==0&&$3.tokentype==0)
			{
				$$.tokentype = 0;
				$$.intval = $1.intval % $3.intval;
			}
			else
				yyerror("type error");
			Trace("< expression '%%' expression >\n");
		}
		| '-' expression %prec UMINUS					// the uminus expression ex: -10 reduce to expression;
		{
			if($2.tokentype==0)
			{
				$$.tokentype=0;
				$$.intval = -$2.intval;
			}
			else if($2.tokentype==1)
			{
				$$.tokentype=1;
				$$.floatval = -$2.floatval;
			}
			else
				yyerror("type error");
			Trace("< '-' expression reduce to expression >\n");
		}
		| '(' expression ')'
		{
			if($2.tokentype==0)
			{
				$$.tokentype = 0;
				$$.intval = $2.intval;
			}
			else if($2.tokentype==1)
			{
				$$.tokentype = 1;
				$$.floatval = $2.floatval;
			}
			else if($2.tokentype==3)
			{
				$$.tokentype = 3;
				$$.stringval = $2.stringval;
			}
			else if($2.tokentype==4)
			{
				$$.tokentype = 4;
				$$.boolval = $2.boolval;
			}
			else
				yyerror("type error");
			Trace("< '(' expression ')' reduce to expression >\n");
		}
		| INTEGER {$$.intval = $1.intval;$$.tokentype=0; Trace("< INTEGER reduce to expression >\n");}
		| Float {$$.floatval = $1.floatval;$$.tokentype=1; Trace("< FLOAT reduce to expression >\n");}
		| NAME														// the id expression ex: a reduce to expression;
		{
			$$.tokentype = returntype(tabcount,$1.stringval);
			if(returntype(tabcount,$1.stringval)==0)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,$1.stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				$$.intval = thetab[choose][index].theint;
			}
			else if(returntype(tabcount,$1.stringval)==1)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,$1.stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				$$.floatval = thetab[choose][index].thefloat;
			}
			else if(returntype(tabcount,$1.stringval)==3)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,$1.stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				strcpy($$.stringval,thetab[choose][index].thestring.c_str());
			}
			else if(returntype(tabcount,$1.stringval)==4)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,$1.stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				$$.boolval = thetab[choose][index].thebool;
			}
			else
				yyerror("type error");
			Trace("< NAME reduce to expression >\n");
		}
		| NAME '[' int_expression ']'						// the array expression ex: a[10] reduce to expression;
		{
			$$.tokentype = returntype(tabcount,$1.stringval);
			if(returntype(tabcount,$1.stringval)==0)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,$1.stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				$$.intval = thetab[choose][index].int_array[$3.intval];
			}
			else if(returntype(tabcount,$1.stringval)==1)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,$1.stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				$$.floatval = thetab[choose][index].float_array[$3.intval];
			}
			else if(returntype(tabcount,$1.stringval)==3)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,$1.stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				strcpy($$.stringval,thetab[choose][index].string_array[$3.intval].c_str());
			}
			else if(returntype(tabcount,$1.stringval)==4)
			{
				int choose = 0;
				int index = 0;
				for(int i =tabcount;i>=0;i--)
				{
					index = returnindex(i,$1.stringval);
					choose = i;
					if(index!=-1)
						break;
				}
				$$.boolval = thetab[choose][index].bool_array[$3.intval];
			}
			else
				yyerror("type error");
			Trace("< NAME '[' int_expression ']' reduce to expression >\n");
		}
		;
if_statement: IF '(' bool_expression ')' block        				{Trace("< IF '(' bool_expression ')' lscope reduce to if_statement >\n");}
		|     IF '(' bool_expression ')' statement             		{Trace("< IF '(' bool_expression ')' statement reduce to if_statement >\n");}
		|	  IF '(' bool_expression ')' block ELSE block			{Trace("< IF '(' bool_expression ')' block ELSE block reduce to if_statement >\n");}
		|	  IF '(' bool_expression ')' statement ELSE block		{Trace("< IF '(' bool_expression ')' statement ELSE block reduce to if_statement >\n");}
		|	  IF '(' bool_expression ')' block ELSE	statement		{Trace("< IF '(' bool_expression ')' block ELSE statement reduce to if_statement >\n");}
		|	  IF '(' bool_expression ')' statement ELSE statement	{Trace("< IF '(' bool_expression ')' statement ELSE statement reduce to if_statement >\n");}
		;
bool_expression: expression EQ expression				// the bool check ex: a==b reduce to bool_expression;
		{
			$$.tokentype=4;
			if($1.tokentype==0&&$3.tokentype==0)
			{
				if($1.intval==$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				if($1.intval==$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				if($1.floatval==$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				if($1.floatval==$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==3&&$3.tokentype==3)
			{
				if(strcmp($1.stringval,$3.stringval)==0)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==4&&$3.tokentype==4)
			{
				if($1.boolval==$3.boolval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else
				yyerror("type error");
			Trace("expression EQ expression reduce to bool_expression\n");
		}
		|   expression GE expression						// the bool check ex: a>=b reduce to bool_expression;
		{
			$$.tokentype=4;
			if($1.tokentype==0&&$3.tokentype==0)
			{
				if($1.intval>=$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				if($1.intval>=$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				if($1.floatval>=$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				if($1.floatval>=$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==4&&$3.tokentype==4)
			{
				if($1.boolval>=$3.boolval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else
				yyerror("type error");
			Trace("< expression GE expression reduce to bool_expression >\n");
		}
		|   expression LE expression					// the bool check a<=b reduce to bool_expression;
		{
			$$.tokentype=4;
			if($1.tokentype==0&&$3.tokentype==0)
			{
				if($1.intval<=$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				if($1.intval<=$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				if($1.floatval<=$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				if($1.floatval<=$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==4&&$3.tokentype==4)
			{
				if($1.boolval<=$3.boolval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else
				yyerror("type error");
			Trace("< expression LE expression reduce to bool_expression >\n");
		}
		|   expression NE expression						// the bool check ex: a != b reduce to bool_expression;
		{
			$$.tokentype=4;
			if($1.tokentype==0&&$3.tokentype==0)
			{
				if($1.intval!=$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				if($1.intval!=$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				if($1.floatval!=$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				if($1.floatval!=$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==3&&$3.tokentype==3)
			{
				if(strcmp($1.stringval,$3.stringval)!=0)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==4&&$3.tokentype==4)
			{
				if($1.boolval!=$3.boolval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else
				yyerror("type error");
			Trace("< expression NE expression reduce to bool_expression >\n");
		}
		|   expression '>' expression							// the bool check ex: a>b reduce to bool_expression;
		{
			$$.tokentype=4;
			if($1.tokentype==0&&$3.tokentype==0)
			{
				if($1.intval>$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				if($1.intval>$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				if($1.floatval>$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				if($1.floatval>$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==4&&$3.tokentype==4)
			{
				if($1.boolval>$3.boolval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else
				yyerror("type error");
			Trace("< expression '>' expression reduce to bool_expression >\n");
		}
		|   expression '<' expression					// the bool check ex: a<b reduce to bool_expression;
		{
			$$.tokentype=4;
			if($1.tokentype==0&&$3.tokentype==0)
			{
				if($1.intval<$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				if($1.intval<$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				if($1.floatval<$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				if($1.floatval<$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==4&&$3.tokentype==4)
			{
				if($1.boolval<$3.boolval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else
				yyerror("type error");
			Trace("< expression '<' expression reduce to bool_expression >\n");
		}
		|   expression AND expression					// the bool check ex: a && b reduce to bool_expression
		{
			$$.tokentype=4;
			if($1.tokentype==0&&$3.tokentype==0)
			{
				if($1.intval&&$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				if($1.intval&&$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				if($1.floatval&&$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				if($1.floatval&&$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==4&&$3.tokentype==4)
			{
				if($1.boolval&&$3.boolval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else
				yyerror("type error");
			Trace("< expression AND expression reduce to bool_expression >\n");
		}
		|   expression OR expression				// the bool check ex: a||b reduce to bool_expression;
		{
			$$.tokentype=4;
			if($1.tokentype==0&&$3.tokentype==0)
			{
				if($1.intval||$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==0&&$3.tokentype==1)
			{
				if($1.intval||$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==0)
			{
				if($1.floatval||$3.intval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==1&&$3.tokentype==1)
			{
				if($1.floatval||$3.floatval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else if($1.tokentype==4&&$3.tokentype==4)
			{
				if($1.boolval||$3.boolval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			else
				yyerror("type error");
			Trace("< expression OR expression reduece to bool_expression >\n");
		}
		|   '!' expression							// the bool check ex: !a reduce to bool_expression
		{
			if($2.tokentype!=4)
				yyerror("type error");
			else{
				$$.tokentype=4;
				if(!$2.boolval)
					$$.boolval = true;
				else
					$$.boolval = false;
			}
			Trace("< '!' expression reduce to bool_expression >\n");
		}
		|   TRUE 	{$$.tokentype=4;$$.boolval=true;Trace("< TRUE reduce to bool_expression >\n");}
		|   FALSE 	{$$.tokentype=4;$$.boolval=false;Trace("< FALSE reduce to bool_expression >\n");}
		;
loop_statement:  WHILE '(' bool_expression ')' block 	{Trace("< WHILE '(' bool_expression ')' block reduece to loop_statement >\n");}
		    |   WHILE '(' bool_expression ')' statement {Trace("< WHILE '(' bool_expression ')' statement reduce to loop_statement >\n");}
		;
Type: INT 		{$$.tokentype=0;Trace("< INT reduce to Type >\n");}			// the type statement to check what the type;
    | FLOAT 	{$$.tokentype=1;Trace("< FLOAT reduce to Type >\n");}
    | STR 		{$$.tokentype=3;Trace("< STR reduce to Type >\n");}
    | BOOL 		{$$.tokentype=4;Trace("< BOOL reduce to Type >\n");}
    ;
string_expression: STRING  {$$.tokentype=3;strcpy($$.stringval,$1.stringval);Trace("< \" STRING \" reduce to string_expression >\n");}
	;
int_expression: int_expression '+' int_expression 	{$$.tokentype=0;$$.intval=$1.intval+$3.intval;Trace("< int_expression '+' int_expression reduce to int_expression >\n");}   // this block is to caculate the expression that only int type;
	|   int_expression '-' int_expression 			{$$.tokentype=0;$$.intval=$1.intval-$3.intval;Trace("< int_expression '-' int_expression reduce to int_expression >\n");}
	|   int_expression '*' int_expression 			{$$.tokentype=0;$$.intval=$1.intval*$3.intval;Trace("< int_expression '*' int_expression reduce to int_expression >\n");}
	|   int_expression '/' int_expression 			{$$.tokentype=0;$$.intval=$1.intval/$3.intval;Trace("< int_expression '/' int_expression reduce to int_expression >\n");}
	|   int_expression '%' int_expression 			{$$.tokentype=0;$$.intval=$1.intval%$3.intval;Trace("< int_expression '%%' int_expression reduce to int_expression >\n");}
	|   '-' int_expression %prec UMINUS 			{$$.tokentype=0;$$.intval=-$2.intval;Trace("< '-' int_expression reduce to int_expression >\n");}
	|   '(' int_expression ')' 						{$$.tokentype=0;$$.intval=$2.intval;Trace("< '(' int_expression ')' reduce to int_expression >\n");}
	|   INTEGER 									{$$.tokentype=0;$$.intval=$1.intval;Trace("< INTEGER reduce to int_expression >\n");}
	|   NAME
	{
		if(returntype(tabcount,$1.stringval)!=0)
			yyerror("type error");
		else{
			$$.tokentype=0;
			int choose = 0;
			int index = 0;
			for(int i =tabcount;i>=0;i--)
			{
				index = returnindex(i,$1.stringval);
				choose = i;
				if(index!=-1)
					break;
			}
			$$.intval = thetab[choose][index].theint;
		}
		Trace("< NAME reduce to int_expression >\n");
	}
	;
function_return: NAME '(' argument ')'          // this block is to get function return value to variable and it reduces to function_return;
	{
		int check = returnfunctiontype($1.stringval);
		if(check==0)
		{
			$$.tokentype=0;
			$$.intval = 0;
		}
		else if(check==1)
		{
			$$.tokentype=1;
			$$.floatval = 0.0;
		}
		else if(check==3)
		{
			string s = "___";
			$$.tokentype=3;
			strcpy($$.stringval,s.c_str());
		}
		else if(check==4)
		{
			$$.tokentype=4;
			$$.boolval = true;
		}
		else
			yyerror("type error");
		Trace("< NAME '(' argument ')' reduce to function_return >\n");
	}
	|	NAME '(' ')'
	{
		int check = returnfunctiontype($1.stringval);
		if(check==0)
		{
			$$.tokentype=0;
			$$.intval = 0;
		}
		else if(check==1)
		{
			$$.tokentype=1;
			$$.floatval = 0.0;
		}
		else if(check==3)
		{
			string s = "___";
			$$.tokentype=3;
			strcpy($$.stringval,s.c_str());
		}
		else if(check==4)
		{
			$$.tokentype=4;
			$$.boolval = true;
		}
		else
			yyerror("type error");
		Trace("NAME '(' ')' reduce to function_return >\n");
	}
	;
function: FN NAME '(' argument ')' '-' '>' Type block     {argudump();$$.stringval=$2.stringval;insertfunction($2.stringval,$8.tokentype);Trace("< FN NAME '(' argument ')' '-' '>' Type block reduce to function >\n");} 		// this block is to declare the function and it reduecs to function;
		| FN NAME '(' ')' '-' '>' Type block              {$$.stringval=$2.stringval;insertfunction($2.stringval,$7.tokentype);Trace("< FN NAME '(' ')' '-' '>' Type block reduce to function >\n");}
		| FN NAME '(' argument ')' block                  {argudump();$$.stringval=$2.stringval;insertfunction($2.stringval,5);Trace("< FN NAME '(' argument ')' block reduce to function >\n");}
		| FN NAME '(' ')' block                           {$$.stringval=$2.stringval;insertfunction($2.stringval,5);Trace("< FN NAME '(' ')' block reduce to function >\n");}
		;
argument: NAME ':' Type         				{if(totalargu==0)argu = (symargu*)malloc(sizeof(symargu)*10);insertargu($1.stringval,$3.tokentype); Trace("< NAME ':' Type reduce to argument >\n");} 			// this block is to declare the function argument and it reduces to argument;
		| NAME ':' Type ',' argument            {insertargu($1.stringval,$3.tokentype);Trace("< NAME ':' Type ',' argument reduce to argument >\n");}
		| argument ',' argument            		{Trace("< argument ',' argument reduce to argument >\n");}
		| expression							{Trace(" <expression reduce to argument >\n");}
		;
%%
//#include "lex.yy.c"
int main()
{
    thetab[0] = (symtab*)malloc(sizeof(symtab)*256);
    /* open the source program file */
    /*if (argc != 2) {
	printf ("Usage: sc filename\n");
	exit(1);
    }*/
    //yyin = fopen(argv[1], "r");         /* open input file */
    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
	yyerror("Parsing error !");     /* syntax error */
    return 0;
}
void createtab(int tabcount)										// under this is to process the symbol table;
{
	thetab[tabcount] = (symtab*)malloc(sizeof(symtab)*256);
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
		thetab[tabcount][push].name=id;
		thetab[tabcount][push].thestate = check;
		thetab[tabcount][push].array_or_not = array_check;
		idcount[tabcount]++;
	}
	else
	{
		if(thetab[tabcount][index].thestate==0)
			yyerror("constant error");
		else
		{
			if(returntype(tabcount,id)==0)
			{
				thetab[tabcount][index].thetype = 0;
				thetab[tabcount][index].theint = 0;
			}
			else if(returntype(tabcount,id)==1)
			{
				thetab[tabcount][index].thetype = 1;
				thetab[tabcount][index].thefloat = 0;
			}
			else if(returntype(tabcount,id)==3)
			{
				thetab[tabcount][index].thetype = 3;
				thetab[tabcount][index].thestring="___";
			}
			else if(returntype(tabcount,id)==4)
			{
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
		thetab[tabcount][push].name=id;
		thetab[tabcount][push].thetype = type;
		thetab[tabcount][push].thestate = check;
		thetab[tabcount][push].array_or_not = array_check;
		idcount[tabcount]++;
	}
	else
	{
		if(thetab[tabcount][index].thestate==0)
			yyerror("constant error");
		else
		{
			if(returntype(tabcount,id)==0)
			{
				thetab[tabcount][index].thetype = type;
				thetab[tabcount][index].theint = 0;
			}
			else if(returntype(tabcount,id)==1)
			{
				thetab[tabcount][index].thetype = type;
				thetab[tabcount][index].thefloat = 0;
			}
			else if(returntype(tabcount,id)==3)
			{
				
				thetab[tabcount][index].thetype = type;
				thetab[tabcount][index].thestring = "___";
			}
			else if(returntype(tabcount,id)==4)
			{
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
	totalargu++;
}
void insertfunction(char *id,int type)
{
	int push = functioncount;
	funtab[push].name = id;
	funtab[push].thetype = type;
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