// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: ALL TEN CIPHERS.cpp
// Last Modification Date: 3/5/2018
// Author1 and ID and Group: Suhail   20170121
// Author2 and ID and Group: Seif     20170125
// Author3 and ID and Group: Mohammed 20170212
// Teaching Assistant: Mohammed Atta and Khadiga
// Purpose:Ciphering and diciphering in ten different ways

#include <bits/stdc++.h>

using namespace std;
string arrs="abcdefghijklmnopqrstuvwxyz";
string arrc="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string crra="ZYXWVUTSRQPONMLKJIHGFEDCBA";
string srra="zyxwvutsrqponmlkjihgfedcba";
vector<char> enc;
vector <string>enc1;
int choice,pos,a,b,c,C=5,indx,nshifts,l,cipher_choice,counter=0,indx1=0,z=16,c_or_s;
string txt,k,bits,bits2, substring;
char key[26],s='a',dshifts;
bool is;

//================================================
//cipher0:
void cipher0()
{   cout<<"Choose what you want to do:"<<endl;
    cout<<"1.Cipher"<<endl;
    cout<<"2.Decipher"<<endl;
cin>>choice;
cin.ignore();
//ciphher
if(choice==1)
{
    //read the text and a,b,c.
    cout<<"please enter the message to cipher:"<<endl;
    getline(cin,txt);
    cout<<"please enter 3 integers a , b and c such that (a*c) % 26 =1:"<<endl;
    cin>>a>>b>>c;
    //error numbers.
    while((a*c)%26!=1)
    {
        cout<<"please enter a valid numbers"<<endl;
        cout<<"please enter 3 integers a , b and c such that (a*c) % 26 =1:"<<endl;
        cin>>a>>b>>c;
    }
    //Pass through the text.
    for(int i=0;i<txt.length();i++)
    {
        if(int(txt[i])>=65&&int(txt[i])<=90)    //capital letters.
            {
                indx=arrc.find(txt[i]);     //see index.
                l=int((a*indx+b)%26);       //apply the formula on index.
                enc.push_back(arrc[l]);     //get the encrypted letter.
            }
            else if(int(txt[i])>=97&&int(txt[i])<=122)  //small letters.
            {
                indx=arrs.find(txt[i]);     //see index.
                l=int((a*indx+b)%26);       //apply the formula on index.
                enc.push_back(arrs[l]);     //get the encrypted letter.
            }
            else if(int(txt[i])==32) //if space !
            {
                enc.push_back(' ');
            }
        }
            cout<<"your encrypted message is:"<<endl;
                for (int j=0; j<enc.size(); j++)
            {
                cout<<enc[j];
            }
            cout<<endl;
            cout<<endl;
            cout<<"========================================================="<<endl;
            enc.erase(enc.begin(),enc.begin()+enc.size());
    }
        //Decipher
        else if(choice==2)
            {
                //read the encrypted text and a,b,c.
                cout<<"please enter the encrypted message :"<<endl;
                getline(cin,txt);
                cout<<"please enter 3 integers a , b and c such that (a*c) % 26 =1:"<<endl;
                        cin>>a>>b>>c;
                        while((a*c)%26!=1)
                    {
                        cout<<"please enter a valid numbers"<<endl;
                        cin>>a>>b>>c;
                    }
                        //Pass through the text.
                        for (int i=0; i<txt.length(); i++)
                    {
                        if(int(txt[i])>=65&&int(txt[i])<=90)    //capital letters.
                    {
                        indx=arrc.find(txt[i]);     //see index.
                        l=int(c*(indx-b)%26);       //apply the formula on index.
                        if(l<0)
                        {
                            l+=26;
                        }
                        enc.push_back(arrc[l]);     //get the encrypted letter.
                    }
                        else if(int(txt[i])>=97&&int(txt[i])<=122)  //small letters.
                    {
                        indx=arrs.find(txt[i]);     //see index.
                        l=int(c*(indx-b)%26);       //apply the formula on index.
                        if(l<0)
                        {
                            l+=26;
                        }
                        enc.push_back(arrs[l]);     //get the encrypted letter.
                    }
                    else if(int(txt[i])==32)        //if apace.
                    {
                        enc.push_back(' ');
                    }
                    }
                    cout<<"your original message is:"<<endl;
                        for(int k=0; k<enc.size(); k++)
                    {
                        cout<<enc[k];
                    }
                    cout<<endl;
                    cout<<endl;
                    cout<<"========================================================="<<endl;
                    enc.erase(enc.begin(),enc.begin()+enc.size());
                    }
}
//================================================================================================
//cipher1:
void cipher1()
{
cout<<"What do you like to do today?"<<endl;
cout<<"1- Cipher a message"<<endl;
cout<<"2- Decipher a message"<<endl;
cin>>choice;
if(choice==1)       //Cipher
{
    cout<<"please enter number of shifts:"<<endl;
    cin>>nshifts;
    cout<<"please enter the direction you want to shift to:"<<endl;
    cin>>dshifts;
    cin.ignore();
    cout<<"please enter the message to cipher:"<<endl;
    getline(cin,txt);
    for(int i=0;i<txt.length();i++)     //Pass through the text.
    {
        if(txt[i]==32)      //if space.
        {
            enc.push_back(' ');
        }
        else if(int(txt[i])>=65&&int(txt[i])<=90)       //capital letters.
        {   if(dshifts=='R')    //right shifts
            {
                pos=arrc.find(txt[i])+nshifts;
                if(pos>=26)
                {
                    pos-=26;
                }
                enc.push_back(arrc[pos]);
        }
        else if(dshifts=='L')   //left shifts
        {
            pos=arrc.find(txt[i])-nshifts;
            if(pos<0)
            {
                pos+=26;
            }
            enc.push_back(arrc[pos]);
        }
    }
    else if(int(txt[i])>=97&&int(txt[i])<=122)      //small letters.
    {
        if(dshifts=='R')
        {
            pos=arrs.find(txt[i])+nshifts;
            if(pos>=26)
            {
                pos-=26;
            }
            enc.push_back(arrs[pos]);
        }
        else if(dshifts=='L')
        {
            pos=arrs.find(txt[i])-nshifts;
            if(pos<0)
            {
                pos+=26;
            }
            enc.push_back(arrs[pos]);
        }
    }
}
for(int j=0;j<enc.size();j++)
    {
        cout<<enc[j];
    }
cout<<endl;
}
if(choice==2)       //Decipher.
{
cout<<"enter number of shifts that have been done"<<endl;
cin>>nshifts;
cout<<"enter the direction that the message shifted to"<<endl;
cin>>dshifts;
cin.ignore();
cout<<"enter the message to decipher:"<<endl;
getline(cin,txt);

for (int i=0;i<txt.length();i++)
{   if(txt[i]==32)
{
    enc.push_back(' ');
}
 else if(int(txt[i])>=65&&int(txt[i])<=90)
        {   if(dshifts=='R')
            {
                pos=arrc.find(txt[i])-nshifts;
                if(pos<0)
                {
                    pos+=26;
                }
                enc.push_back(arrc[pos]);
        }
        else if(dshifts=='L')
        {
            pos==arrc.find(txt[i])+nshifts;
            if(pos>=26)
            {
                pos-=26;
            }
            enc.push_back(arrc[pos]);
        }
    }
    else if(int(txt[i])>=97&&int(txt[i])<=122)
    {
        if(dshifts=='R')
        {
            pos=arrs.find(txt[i])-nshifts;
            if(pos<0)
            {
                pos+=26;
            }
            enc.push_back(arrs[pos]);
        }
        else if(dshifts=='L')
        {
            pos=arrs.find(txt[i])+nshifts;
            if(pos>=26)
            {
                pos-=26;
            }
            enc.push_back(arrs[pos]);
        }
    }
}
cout<<"your original message is:"<<endl;
for(int j=0;j<enc.size();j++)
    {
        cout<<enc[j];
    }
cout<<endl;

}
cout<<"======================================"<<endl;
}
//======================================================================================
//cipher2:
void cipher2()
{
cout<<"What do you like to do today?"<<endl;
cout<<"1- Cipher a message"<<endl;
cout<<"2- Decipher a message"<<endl;
cin>>choice;
cin.ignore();
if(choice==1)       //cipher
{
    cout<<"please enter a message to cipher:"<<endl;
    getline(cin,txt);
    for(int i=0;i<txt.length();i++)     //pass throw the text.
    {
        if(int(txt[i])==32)
        {
            enc.push_back(' ');
        }


        else if(int(txt[i])>=65&&int(txt[i])<=90)       //capital
        {
           pos=arrc.find(txt[i]);
           enc.push_back(crra[pos]);
        }
        else if (int(txt[i])>=97&&int(txt[i])<=122)     //small
        {
            pos=arrs.find(txt[i]);
            enc.push_back(srra[pos]);
        }
    }
    cout<<"your encrypted message is:"<<endl;
    for(int j=0;j<enc.size();j++)
    {
        cout<<enc[j];
    }
    cout<<endl;


}
else if(choice==2)      //Decipher
{
    cout<<"please enter your encrypted message:"<<endl;
    getline(cin,txt);
    for(int i=0;i<txt.length();i++)
    {
        if(int(txt[i])==32)
        {
            enc.push_back(' ');
        }
        else if(int(txt[i])>=65&&int(txt[i])<=90)       //capital
        {
            pos=crra.find(txt[i]);
            enc.push_back(arrc[pos]);
        }
        else if(int(txt[i])>=97&&int(txt[i])<=122)      //small
        {
            pos=srra.find(txt[i]);
            enc.push_back(arrs[pos]);
        }
    }
    cout<<"your original message is:"<<endl;
    for(int j=0;j<enc.size();j++)
    {
        cout<<enc[j];
    }
    cout<<endl;
}
cout<<"======================================"<<endl;

}

//======================================================================================
//cipher3:
void cipher3()
{
cout<<"What do you like to do today?"<<endl;
cout<<"1- Cipher a message"<<endl;
cout<<"2- Decipher a message"<<endl;
cin>>choice;
cin.ignore();
if(choice==1)
{
 cout<<"please enter the message to cipher"<<endl;
 getline(cin,txt);
 for (int i=0;i<txt.length();i++)
 {
     if(int(txt[i])==32)
     {
         enc.push_back(' ');
     }


     else if(int(txt[i])>=65&&int(txt[i]<=90))
     {
         pos=arrc.find(txt[i])+13;
         if(pos>26)
         {
             pos-=26;
         }
         enc.push_back(arrc[pos]);
     }
     else if(int(txt[i])>=97&&int(txt[i])<=122)
     {
         pos=arrs.find(txt[i])+13;
         if(pos>26)
         {
             pos-=26;
         }
         enc.push_back(arrs[pos]);
     }

 }
 cout<<"your encrypted message is"<<endl;
 for(int j=0;j<enc.size();j++)
 {
     cout<<enc[j];
 }
 cout<<endl;
}
else if(choice==2)
{   cout<<"please enter the encrypted message:"<<endl;
    getline(cin,txt);
    for(int i=0;i<txt.length();i++)
    {
        if(int(txt[i])==32)
        {
            enc.push_back(' ');
        }


        if(int(txt[i])>=65&&int(txt[i])<=90)
        {
            pos=arrc.find(txt[i])-13;
            if(pos<0)
            {
                pos+=26;
            }
            enc.push_back(arrc[pos]);
        }
        else if(int(txt[i])>=97&&int(txt[i])<=122)
        {
            pos=arrs.find(txt[i])-13;
            if(pos<0)
            {
                pos+=26;
            }
            enc.push_back(arrs[pos]);
        }
    }
    cout<<"your original message is:"<<endl;
    for(int j=0;j<enc.size();j++)
    {
        cout<<enc[j];
    }
    cout<<endl;
}
cout<<"======================================"<<endl;

}
//============================================================================
//cipher4:
void cipher4()
{
    vector<char>w;
char arr[27] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 string ar[27]={"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab"};
string s;       //input massage from the user
int z;  //z to choose 1-cipher or 2-decipher
int decimal=0,counter=0;

cout<<"welcome"<<endl;
cout<<"choose a number"<<endl;
cout<<"1-Cipher"<<endl;
cout<<"2-Decipher"<<endl;

cin>>z ;
cin.ignore();
if(z==1){
  cout<<"ENTER THE MESSAGE"<<endl;
  getline(cin,s);
  for(int i=0;i<s.length();i++)
  {
      for(int j=0;j<26;j++)
      {
         if(s[i]==arr[j])
         {
             cout<<ar[j]<<" ";
         }
      }
  }
cout<<endl; }
  else if(z==2)
  {
    cout<<"ENTER THE MESSAGE"<<endl;
     cin>>s;
     for(int i=1 ;i<=(int)s.size();i++)
     {
         if((s[i-1]=='b') || (s[i-1]=='a'))
         {
             if((s[i-1]=='b'))
             {
                 decimal=decimal+pow(2,4-counter);      //formula for knowing the corresponding character.
             }
             if((i%5)==0)       //to print one character every 5 letters.
             {
                 cout<<arr[decimal];
                 decimal=0;
             }
         }
       counter++;
       if(i%5==0)
       {
           counter=0;
       }
     }

 cout << endl;
  }
cout<<"======================================"<<endl;

}

//=============================================================================
//cipher5:
void cipher5()
{
    cout<<"What do you like to do today?"<<endl;
    cout<<"1- Cipher a message"<<endl;
    cout<<"2- Decipher a message"<<endl;
    cin>>choice;
    cin.ignore();
    if(choice==1)
    {
        cout<<"Please enter the message to cipher:"<<endl;
        getline(cin,txt);

        cout<<"please enter the first 5 letters of the key:"<<endl;
        cin>>k;
        for (int i=0; i<5; i++)
        {
            key[i]=k[i];
        }
loop:

        for (int j=0; j<5; j++)
        {
            if(s!=k[j]&&s!=122)
            {
                is=true;
            }
            else if(s==k[j]&s!=122)
            {
                s++;
                goto loop;
            }

        }
        if(is==true&&C<27)
        {
            key[C]=s;
            s++;
            C++;
            goto loop;
        }
         for (int q=0; q<txt.length(); q++)
    {
        for (int u=0; u<26; u++)
        {
            if(int(txt[q])==32)
            {
                enc.push_back(' ');
                break;
            }
            if(txt[q]==arrs[u])
            {
                enc.push_back(key[u]);
            }

        }
    }
    cout<<"Your encrypted text :"<<endl;
    for (int v=0; v<enc.size(); v++)
    {
        cout<<enc[v];
    }
    }

else if (choice==2)
    {
        cout<<"Please enter the encrypted text :"<<endl;
        getline(cin,txt);
        cout<<"please enter the first 5 letters of the key:"<<endl;
        cin>>k;
            for (int i=0; i<5; i++)
    {
        key[i]=k[i];
    }
loop1:

    for (int j=0; j<5; j++)
    {
        if(s!=k[j]&&s!=122)
        {
            is=true;
        }
        else if(s==k[j]&s!=122)
        {
            s++;
            goto loop1;
        }

    }
    if(is==true&&C<27)
    {
        key[C]=s;
        s++;
        C++;
        goto loop1;
    }
for (int q=0; q<txt.length(); q++)
    {
        for (int u=0; u<26; u++)
        {
            if(int(txt[q])==32)
            {
                enc.push_back(' ');
                break;
            }
            if(txt[q]==key[u])
            {
                enc.push_back(arrs[u]);
            }

        }
    }
cout<<"The original text is:"<<endl;
        for (int v=0; v<enc.size(); v++)
        {
            cout<<enc[v];
        }






}
cout<<"======================================"<<endl;
}
//===================================================================
//cipher6:
void Polybius_Square_Cipher()
{
     int key_array[6];
    char matrix[5][5];
    char letter ='A';
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if (letter=='W')
            {
                letter++;
            }

            matrix[i][j]=letter++;

        }
    }

    cout << "Enter 1 if you want a cipher or 2 if you want to dicipher";
    int cases;
    cin >> cases;

    if (cases ==1)
    {
        cout << "Pls Enter your key : ";
    string key;
    cin >> key;
    cin.ignore();
    cout << "pls enter your message : ";
    string msg;
    getline(cin,msg);
        for(int i=0;i<msg.length();i++)
        { int index;
            if (msg[i]>='a'&&msg[i]<='z')
            {
                index =msg[i]-'a';
                cout << key[index/5] << key[index%5];
            }
            else if (msg[i]>='A'&&msg[i]<='Z')
            {
                index=msg[i]-'A';
                cout << key[index/5] << key[index%5];
            }
            else
            {
                cout << msg[i];
                continue;
            }

        }
    }
    else
    {

        cout << "Pls Enter your key(each integer is seprated : " << endl;
        for(int i=0;i<5;i++)
        {int x;
            cin >> x ;
            if(x>5)
            {
                cout << "Wrong input ,pls each digit is separated ";
                i--;
                continue;
            }
             key_array[x]=i;
        }

    cin.ignore();
    cout << "pls enter your message : ";
    string msg;
    getline(cin,msg);
        for(int i=0;i<msg.length();)
        {
            if(msg[i]<'1'||msg[i]>'5')
            {
                cout << msg[i];
                i++;
                continue;
            }

            else
            {

              int r=int(msg[i]-'0'),c=int(msg[i+1]-'0');
              r=key_array[r];c=key_array[c];
              cout << matrix[r][c];
             i+=2;

            }



    }
    }
    cout<<endl;
}


//===================================================================
//cipher7:
void cipher7()
{   int cases;
    string morse[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string msg,decrypted_msg,decrypted_letter;
    bool isSpace=false;
    cout << "Enter 1 for cipher or 2 for dicipher ";
    cin >> cases;
    cout << "Enter your message : " << endl;
    cin.ignore();
    getline(cin,msg);
    if (cases==1)
    {
        for(int i=0;i<msg.size();i++)
        {
            if (msg[i]==' ')
             cout << "   ";
             else if (msg[i]>='A'&&msg[i]<='Z')
                 cout << morse[msg[i]-'A'] << " ";
             else if (msg[i]>='a'&&msg[i]<='z')
                 cout << morse[msg[i]-'a'] << " ";
        }
        cout << endl;

    }
    else
    {
        for(int i=0;i<msg.size();)
        {
             if(i==msg.size()-1)
            {
             decrypted_letter+=msg[i];
                for(int j=0;j<26;j++)
                {

                    if (decrypted_letter==morse[j])
                    {
                        cout << char(j+'A') ;
                        decrypted_letter="";
                        isSpace=true;
                        break;
                    }
                }
                break;
            }


           else if(decrypted_letter.size()!=0&&msg[i]==' ')
            {

                for(int j=0;j<26;j++)
                {

                    if (decrypted_letter==morse[j])
                    {
                        cout << char(j+'A') ;
                        decrypted_letter="";
                        isSpace=true;
                        break;
                    }
                }
                i++;
            }
            else if(msg[i]!=' ')
            {
                decrypted_letter+=msg[i];
                i++;
            }
            else if(msg[i]==' '&&isSpace==true)
            {
              cout << ' ';
              i+=3;
              isSpace=false;
            }

        }
        cout<<"======================================"<<endl;
    }
}
//===================================================================
//cipher8:
void XOR_Cipher()
{
     int cases,cases2;
long long hex_encrypted;
  string msg,encrypted_msg,decrypted_msg;
  char key;
  cout << "For Cipher enter 1 or 2 for diCipher : ";
  cin >> cases;
 cin.ignore();
  if (cases ==1){
        cout << "Enter the msg : ";
  getline(cin,msg);
  cout << "Enter the key letter : ";
  cin >> key;
  int x_key =int(key);
  for(int i=0;i<msg.length();i++)
  {
         int x =int(msg[i]);
      int y=x^x_key;
      if (y<16 )
        cout << 0;
      cout << hex  <<y;
      encrypted_msg+=char(y);

  }
  cout << endl << encrypted_msg;
  }
  else
  {
      cout << "1 if you want to enter text ,2 if you want to enter hexa :";
      cin >> cases2;
     cin.ignore();
      if (cases2==1)
      {
            cout << "Enter the msg : ";
      getline(cin,msg);
      cout << "Enter the key letter : ";
      cin >> key;
      int x_key =int(key);
            for(int i=0;i<msg.length();i++)
  {   int x =int(msg[i]);
      int y=x^x_key;
      if (y<16 )
        cout << 0;
      cout << hex  <<y;
      encrypted_msg+=char(y);

  }
  cout << endl << encrypted_msg;

      }
      else
      {
    cout << "Enter the msg  : ";
    getline(cin,msg);
      cout << "Enter the key letter : ";
      cin >> key;
      int x_key =int(key);
     for(int i=0;i<msg.size();i+=2)
     {  int x1=0;
         if(msg[i]>='0'&&msg[i]<='9')
         { int y1;
         string s="";
         s+=msg[i];
             stringstream geek(s);
             geek >> y1;
             x1+=(y1*16);
         }
         else if (msg[i]=='a'||msg[i]=='A')

             x1+=(10*16);

         else if(msg[i]=='b'||msg[i]=='B')

             x1+=(11*16);

         else if(msg[i]=='c'||msg[i]=='C')

             x1+=(12*16);
         else if(msg[i]=='d'||msg[i]=='D')
                x1+=(13*16);
         else if(msg[i]=='e'||msg[i]=='E')
            x1+=(14*16);
         else if(msg[i]=='f'||msg[i]=='F')
            x1+=(15*16);


         if(msg[i+1]>='0'&&msg[i+1]<='9')
         {
             int z;
             string s1="";
             s1+=msg[i+1];
             stringstream geek2(s1);
             geek2 >> z;

             x1+=z;
         }
         else if (msg[i+1]=='a'||msg[i+1]=='A')

             x1+=10;

         else if(msg[i+1]=='b'||msg[i+1]=='B')

             x1+=11;

         else if(msg[i+1]=='c'||msg[i+1]=='C')

             x1+=12;
         else if(msg[i+1]=='d'||msg[i+1]=='D')
                x1+=13;
         else if(msg[i]=='e'||msg[i+1]=='E')
            x1+=14;
         else if(msg[i+1]=='f'||msg[i+1]=='F')
            x1+=15;


         int y2=x1^x_key;
         decrypted_msg+=char(y2);
         if(y2<=15)
            cout << 0;
         cout << hex << y2;
     }
    cout << endl << decrypted_msg << endl;

      }
    cout<<"======================================"<<endl;
  }


}

//===================================================================
//cipher9:

void Rail_fence()
{   int nRails,cases,distance,distance2=2,j=0,row=1,k=0,l=0,index=0;
    string msg,encrypted_msg="";
    bool isDone;

    cout << "Enter 1 for cipher or 2 for dicipher : ";
    cin >> cases;

    if (cases==1)
    {
        cout << "Enter the number of rails : ";
    cin >> nRails;
    distance=(nRails-2)*2+2;
    cin.ignore();
    cout << "Enter the message : ";
    getline(cin,msg);
     for(int i=0;i<msg.size();i++)
     {
         if(msg[i]==' ')
            msg=msg.substr(0,i)+msg.substr(i+1,msg.size()-(i+1));
     }


        while(encrypted_msg.size()<msg.size())
        {
            bool isFirst=false;
           cout << encrypted_msg .size() << endl;
            for(int i=j;i<msg.size();)
            {
                encrypted_msg+=msg[i];
                if(row==1||row==nRails)
                {
                i+=distance;
                }
                else
                {
                    if(isFirst==false)
                    {
                        i+=distance;
                        isFirst=true;
                    }
                    else
                    {
                        i+=distance2;
                        isFirst=false;
                    }
                }

                }
                   if(row!=nRails-1)
             distance-=2;
            else
                distance=(nRails-2)*2+2;
            if(row!=1)
                distance2+=2;

            row++;
            j++;
            }
         cout << encrypted_msg;
        }

    int i,first_distance,z,length,c,b,x,q,g;
    int arr[100]={0};
    string ciphered_message,original_message;
    cout<<"please enter number of rails : "<<endl;
    cin>>row;
    cout<<"please enter the ciphered message :"<<endl;
    cin.ignore();
    getline(cin,ciphered_message);

    for(int o=0;o<ciphered_message.size();o++)
    {
        if(ciphered_message[o]==' ')
        {
            ciphered_message=ciphered_message.substr(0,o)+ciphered_message.substr(o+1,ciphered_message.size()-(o+1));
            o--;
        }
    }


    z=1;
    i=0;
    k=0;
    c=0;
    x=0;
    q=0;
    g=-1;
    distance=(2*row)-2;
    first_distance=distance;
    length=ciphered_message.length();
    while(z==1){
     if(i>=length){
        row-=1;
        k++;
        i=k;
        distance-=2;
        c=0;

        if(distance<2){
            distance=first_distance;
        }

        }

    for(;i<length;i+=distance){

        arr[x]=i;

        x++;
        c++;



        if(c>=2 && (first_distance-distance)!=0 ){

            b=first_distance-distance;
            if(i+b<length){
            i+=b;
            arr[x]=i;
            x++;
            }
       }
    }
    while(row==1){
        g++;
        if(g==length){
        cout<<endl<<"your original message is :" <<endl;
        cout<< original_message;
        isDone=true;
        break;
        }
        else if(arr[q]==g){
            int s;
            s=q;
            original_message+=ciphered_message[s];
            q=0;
        }
        else {
            g--;
            q++;
        }


    if (isDone==true)
        break;

    }

        }

    cout<<"======================================"<<endl;

}


//===================================================================





int main()
{
while(!cin.eof())
{cout<<"Ahlan ya user ya habibi."<<endl;
cout<<"please choose the cipher you want to do"<<endl;
cout<<"0.Affine Cipher "<<endl;
cout<<"1.Caesar Cipher "<<endl;
cout<<"2.Atbash Cipher "<<endl;
cout<<"3.ROT13 Cipher "<<endl;
cout<<"4.Baconian Cipher "<<endl;
cout<<"5.Simple Substitution Cipher "<<endl;
cout<<"6.Polybius Square Cipher "<<endl;
cout<<"7.Morse Code "<<endl;
cout<<"8.XOR Cipher "<<endl;
cout<<"9.Rail-fence Cipher "<<endl;
cout<<"10.End "<<endl;
cin>>cipher_choice;
if(cipher_choice==0)
{
    cipher0();
}
else if(cipher_choice==1)
{
    cipher1();
}
else if(cipher_choice==2)
{
    cipher2();
}
else if(cipher_choice==3)
{
    cipher3();
}
else if(cipher_choice==4)
{
    cipher4();
}
else if(cipher_choice==5)
{
    cipher5();
}
else if(cipher_choice==6)
{
    Polybius_Square_Cipher();
}
else if(cipher_choice==7)
{
    cipher7();
}
else if(cipher_choice==8)
{
    XOR_Cipher();
}
else if(cipher_choice==9)
{
    Rail_fence();
}
else if(cipher_choice==10)
{
    return 0;
}
cout<<"\n"<<"================================================="<<endl;
}
    return 0;
}
