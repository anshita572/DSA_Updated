//https://bit.ly/3sfP71Q 
string replaceSpaces(string &str){
	string temp=""; //creating a string temp
        for(int i=0;i<str.length();i++)
        {
            if(str[i]==' ')
            {temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');}
            else  //if there is no space and normal character is encountered
            {temp.push_back(str[i]);}
        }
    return temp;
}