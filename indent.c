#include <stdio.h>
int main (void)
{
        int ch,tabs,i,paren,a;
        ch=getchar();
        paren=0.0;              /*counter for parenthesis */
        tabs=0.0;               /*counter for tabs*/
        a=0.0;                  /*index for tabs after '{' and '}' and ';' and '\n' */
        while( ch!=EOF)
        {
                switch(ch)
                {
                        case'#':
                                        putchar(ch);      /*if  ch == # type until you fine newline */
                                        while(ch!='\n' )
                                        {
                                                 ch=getchar();
                                                 if(ch==EOF){break;}
                                                 putchar(ch);
                                        }
                                                break;
                        case '{':a=1;
                                         tabs++;
                                         putchar('\n');
                                         for(i=1;i<tabs;i++)
                                         {
                                                putchar('\t');
                                         }
                                         putchar(ch);
                                         putchar('\n');
                                         break;
                        case '}':a=2;
                                        for(i=1;i<tabs;i++)
                                        {
                                                putchar('\t');
                                        }
                                        putchar(ch);
                                        putchar('\n');
                                        tabs--;
                                        break;
                        case '\'':
                                        if(a==1 || a==2 || a==3)        /*if the line starts with \' then put tabs like its was default*/
                                        {
                                                for(i=1;i<=tabs;i++)
                                                {
                                                putchar('\t');
                                                }
                                                a=0;
                                        }
                                        putchar(ch);
                                        ch=getchar();
                                        if(ch==EOF){break;}
                                        while (ch!='\'')
                                        {
                                             putchar(ch);
                                             ch=getchar();
                                             if(ch==EOF){break;}
                                        }
                       					if (ch=='\''){putchar(ch);}
                                        break;
                        case'\"':
                                        if(a==1 || a==2 || a==3)         /*if the line starts with \" then put tabs like its was default*/
                                        {
                                                for(i=1;i<=tabs;i++)
                                                {
                                                        putchar('\t');
                                                }
                                                a=0;
                                        }
                                        putchar(ch);
                                        ch=getchar();
                                        if(ch==EOF){break;}
                                        while(ch!='\"')
                                        {
                                                putchar(ch);
                                                ch=getchar();
                                                if(ch==EOF){break;}
                                        }
                                        break;

                        case '\n':
                                        if(a==0 && tabs>0 ){a=4;} /*we use this if, in case after new line we need a spaceand we alredy saw the first }*/
                                                                        /*example when after newline theres an int or long etc.*/
                                        while(ch=='\n')
                                        {
                                                ch=getchar();                   /*else we take the next char*/
                                                if(ch==EOF){break;}
                                        }
                            			continue;

                        case '\t':
                                        while(ch=='\t'){ch=getchar();}
                                        if(ch==EOF){break;}
                                        continue;

                        case ' ':
                                        ch=getchar();
                                        if(ch==';'|| ch=='}'|| ch=='{'  ){continue;}/*if after space theres one of those chars then exit this case*/
                                        else  if(ch==EOF){break;}
                                        else if (ch==' ')
                                        {
                                                        while(ch==' ')  /*if there are a lot of spaces after the first one replace them with one space*/
                                                        {
                                                                ch=getchar();
                                                                if(ch==EOF){break;}
                                                                putchar(' ');
                                                        }
                                                        continue;
                                                }
                                        else{putchar(' '); continue;}   /*if there is a default char after space just print the space */
                                        break;
                        case '(':
                                        paren++;                /*if ch== ( then paren gets +1*/
                                        putchar(ch);
                                        ch=getchar();
                                        if(ch==EOF){break;}
                                        if(ch==' ')
                                        {
                     while(ch==' ')          /*erase  spaces inside parenthesis*/
                                                {
                                                        ch=getchar();
                                                }
                                                if(ch==EOF){break;}
                                                if(tabs>0)              /*if we already saw { then repace all the spaces with one*/
                                                {
                                                        putchar(' ');
                                                }
                                        }
                                        if(ch=='\n')
                                        {
                                                ch=getchar();
                                                if(ch==EOF){break;}
                                        }
                                        if(ch==')'){ paren--;}          /*if ch== ) then paren gets -1*/
                                        if(ch=='\'')
                                        {
                                                putchar(ch);
                                                ch=getchar();
                                                if(ch==EOF){break;}
                                                while (ch!='\'')
                                                {
                                                        putchar(ch);
                                                        ch=getchar();
                                                        if(ch==EOF){break;}
                                                }
                                        }
                                        if(ch=='\"')
                                        {
   												putchar(ch);
                                                ch=getchar();
                                                if(ch==EOF){break;}
                                                while(ch!='\"')
                                                {
                                                        putchar(ch);
                                                        ch=getchar();
                                                        if(ch==EOF){break;}
                                                }
                                        }
                                        while( paren!=0 )       /*print whats inside the parenthesis until paren goes to zero*/
                                        {
                                                putchar(ch);
                                                ch=getchar();
                                                if(ch==EOF){break;}
                                                if(ch=='\n')
                                                {
                                                        ch=getchar();
                                                        if(ch==EOF){break;}
                                                        putchar(' ');
                                                }
                                                if(ch==' ')
                                                {       while(ch==' ')
                                                        {
                                                                ch=getchar();
                                                        }
                                                        if(ch==EOF){break;}
                                                        putchar(' ');
                                                }
                                                if(ch=='\t')
                  								{       putchar(' ');
                                                        ch=getchar();
                                                        if(ch==EOF){break;}
                                                }
                                                if(ch==')'){paren--;}
                                                if(ch=='('){paren++;}
                                                }
                                                if(ch==')' && paren==0){putchar(')');} /*when paren goes to zero then print the last parenthesis */
                                                break;
                        case ';':a=3;
                                                 putchar(ch);
                                                 putchar('\n');
                                                 break;
                        default:
                                                if(a==1 || a==2 ||a==3)         /*prints tabs after } or { or ; */
                                                {
                                                        for(i=1;i<=tabs;i++){putchar('\t');}
                                                        a=0;
                                                }
                                                else if(a==4)                   /*we get here in case we need one space after newline*/
                                                {
                                                        putchar(' ');
                                                        a=0;
                                                }
                                                putchar(ch);

                }
                ch=getchar();
                if(ch==EOF){break;}
        }
}









