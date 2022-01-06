class Solution {
public:
    string gcd2(string str1,string str2, string res, string res2)
    {
        if(res2.length()>res.length())
        {
            string temp=res;
            res=res2;
            res2=temp;
        }
        int str1len=str1.length();
        int str2len=str2.length();
        int reslen=res.length();
        int res2len=res2.length();
        int str1index=0,str2index=0;
        int i=0,j=0;
        //cout<<res.length()<<":reslength\t"<<res2.length()<<":res2length\n";
        while(i<str1len||j<str2len)
        {
            if(i<str1len)
            {
                for(int k=0;k<res2len;k++)
                {
                    if(str1[i+k]!=res2[k])
                    {
                        if((i+k)==str1len)
                            break;
                        //cout<<"str1:"<<str1[i+k]<<"---"<<res2[k]<<":res2\n";
                        //cout<<"str1 break str[i+k]: "<<str1.substr(0,i+k)<<"\tres2[k]"<<res2.substr(0,k)<<"\n";
                        return "";
                    }    
                }
                i=i+res2len;
            }
            if(j<str2len)
            {
                for(int k=0;k<res2len;k++)
                {
                    if(str2[j+k]!=res2[k])
                    {
                        if((j+k)==str2len)
                            break;
                        //cout<<"str2 break\n";
                        return "";
                    }
                        
                }
                j=j+res2len;
            }
        }
        if(reslen==res2len)
            return res;
        
        string temp=res2;
        res2=res.substr(res2.length(),res2.length()-res.length());
        res=temp;
        return gcd2(str1,str2,res,res2);
    }
    string gcdOfStrings(string str1, string str2) {
        string res="";
        int str1len=str1.length();
        int str2len=str2.length();
        int n=min(str1len,str2len);
        int i=0;
        while(i<n)
        {
            if(str1[i]!=str2[i])
            {
                //cout<<"Basic break\n";
                return "";
            }    
            i++;
        }
        if(str1len==str2len)
            return str1;;
        //cout<<"gcd call\n";
        return gcd2(str1,str2,str1,str2);


    }
};