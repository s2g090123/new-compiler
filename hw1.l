%{
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"y.tab.h"
using namespace std;
#define LIST strcat(buff,yytext)
#define LIST2 strcat(buff2,yytext)
#define token(t) {LIST; printf("<'%s'>\n",yytext);return (t);}
#define tokenInteger(t) {LIST; printf("<integer:%d>\n",t);return INTEGER;}
#define tokenFloat(t) {LIST; printf("<float:%f>\n",t);return Float;}
#define tokenExp(t) {LIST; printf("<exponential:%s>\n",t);}
#define tokenString(t) {LIST; printf("<identifier:%s>\n",t);return NAME;}
//#define createTable() {buff3 = (char **)malloc(256*sizeof(char*));for(int i=0;i<256;i++){buff3[i] = (char *)malloc(256*sizeof(char));}}
//#define lookup() ({for(int i=0;i<idcount;i++){if(yyleng==strlen(buff3[i]))for(int j=0;j<yyleng;j++){if(yytext[j]!=buff3[i][j]){check = 0;break;}if(j==yyleng-1){check=1;break;}}if(check==1)break;if(i==idcount-1){check=0;}}})
//#define insert() {if(check==0){for(int i =0;i<yyleng;i++){buff3[idcount][i]=yytext[i];}idcount++;}}
//#define dump() {printf("Symbol Table: \n");for(int i=0;i<idcount;i++){printf("%s\n",buff3[i]);}}
int linecount = 0;
char buff[256];
char buff2[256];
char **buff3;
extern "C" {
  int yylex();
  int yywrap();
}
%}

operator [\+\-\*\/\++\--\%\<\<=\>=\>=\=\!=\&&\||\!=\+=\-=\*=\/=]
delimiter [","":"";""("")""[""]""{""}"]
keyword ["bool""break""char""continue""do""else""enum""extern""false""float""for""fn""if""in""int""let""loop""match""mut""print""println""pub""return""self""static""str""struct""true""use""where""while"]
digs [0-9]+
integer [-+]?{digs}
plain_real [+-]?{digs}"."{digs}
expreal [+-]?{digs}"."{digs}[Ee][+-]?{digs}
real {plain_real}|{expreal}
letter [A-Z_a-z]
newline [\n]
blank_chars [ \t]+
id {letter}({letter}|{integer})*
quote1 \"
quote2 (\\.|[^"\\])*
%x COMMENT1
%x COMMENT2
%x COMMENT3

%%
"//" {LIST; BEGIN COMMENT1;}
"/*" {LIST; BEGIN COMMENT2;}

"++" {token(PLUS_PLUS);}
"--" {token(MINUS_MINUS);}
"<=" {token(LE);}
">=" {token(GE);}
"==" {token(EQ);}
"!=" {token(NE);}
"+=" {token(PLUS_EQ);}
"-=" {token(MINUS_EQ);}
"*=" {token(MUL_EQ);}
"/=" {token(DIV_EQ);}
"+" {token('+');}
"-" {token('-');}
"*" {token('*');}
"/" {token('/');}
"%" {token('%');}
"<" {token('<');}
">" {token('>');}
"&&" {token(AND);}
"||" {token(OR);}
"!" {token('!');}
"=" {token('=');}

"," {token(',');}
":" {token(':');}
";" {token(';');}
"(" {token('(');}
")" {token(')');}
"[" {token('[');}
"]" {token(']');}
"{" {token('{');}
"}" {token('}');}

"bool" {token(BOOL);}
"break" {token(BREAK);}
"char" {token(CHAR);}
"continue" {token(CONTINUE);}
"do" {token(DO);}
"else" {token(ELSE);}
"enum" {token(ENUM);}
"extern" {token(EXTERN);}
"false" {yylval.Token.boolval=false;token(FALSE);}
"float" {token(FLOAT);}
"for" {token(FOR);}
"fn" {token(FN);}
"if" {token(IF);}
"in" {token(IN);}
"int" {token(INT);}
"let" {token(LET);} 
"loop" {token(LOOP);}
"match" {token(MATCH);}
"mut" {token(MUT);}
"print" {token(PRINT);}
"println" {token(PRINTLN);}
"pub" {token(PUB);}
"return" {token(RETURN);}
"self" {token(SELF);}
"static" {token(STATIC);}
"str" {token(STR);}
"struct" {token(STRUCT);}
"true" {yylval.Token.boolval=true;token(TRUE);}
"use" {token(USE);}
"where" {token(WHERE);}
"while" {token(WHILE);}

{id} {yylval.Token.stringval=strdup(yytext);tokenString(yytext);}
{expreal} {tokenExp(yytext);}
{real} {yylval.Token.floatval=atof(yytext);tokenFloat(atof(yytext));}
{integer} {yylval.Token.intval=atoi(yytext);tokenInteger(atoi(yytext));}
{blank_chars} {if(buff[0]!='\0'){LIST;}}
{newline} {printf("%d: %s\n",linecount,buff);linecount++;buff[0]='\0';}
{quote1} {LIST;BEGIN COMMENT3;}
. {LIST;printf("%d:%s\n",linecount,buff);printf("bad character:'%s'\n",yytext);exit(-1);}

<COMMENT1>{id} {LIST;}
<COMMENT1>{real} {LIST;}
<COMMENT1>{blank_chars} {LIST;}
<COMMENT1>{newline} {LIST;printf("%d: %s",linecount,buff);linecount++;buff[0]='\0'; BEGIN 0;}
<COMMENT1>. {LIST;}

<COMMENT2>{id} {LIST;}
<COMMENT2>{real} {LIST;}
<COMMENT2>{blank_chars} {LIST;}
<COMMENT2>"*/" {LIST;BEGIN 0;}
<COMMENT2>{newline} {LIST;printf("%d: %s",linecount,buff);linecount++;buff[0]='\0';}
<COMMENT2>. {LIST;}

<COMMENT3>{quote2} {LIST;LIST2;}
<COMMENT3>{quote1}{quote1} {LIST;strcat(buff2,"\"");}
<COMMENT3>{quote1} {yylval.Token.stringval=strdup(buff2);LIST;printf("<string:%s>\n",buff2);buff2[0]='\0';BEGIN 0;return STRING;}

%%
/*int lookup(char *s) {
  for(int i=0;i<idcount;i++)
  {
    if(strcmp(buff3[i],s)==0)
        return i;
  }
  return -1;
}
int insert(){
  if(lookup(yytext)==-1)
  {
    strcpy(buff3[idcount],yytext);
    idcount++;
  }
  return idcount-1;
}
int dump(){
  printf("symbol table\n");
  for(int i =0;i<idcount;i++)
    printf("%s\n",buff3[i]);
  return idcount;
}*/
/*int main(){
  //createTable();
  yylex();
  //dump();
  return 0;
}*/
int yywrap(){
  return 1;
}
