#include<bits/stdc++.h>
using namespace std;
string camel_case_converter(string s, bool hyphen, bool only_hyphen = 0){
    int n = s.length();
    if(!only_hyphen)
        s[0] = toupper(s[0]);
    for (int i = 0; i < n; i++) {
        if (s[i] == ' '){
            if(hyphen)
                s[i] = '-';
            if(!only_hyphen)
                s[i + 1] = toupper(s[i + 1]);
            continue;
        }      
    }
    return s;
}
string replaceSpaces(string input){
    string rep = "%20";
    input[0] = toupper(input[0]);
    for(int i=1 ; i<input.length() ; i++){
        if(input[i] == ' '){
            input.replace(i,1,rep);
            input[i+4] = toupper(input[i+4]);
        }
    }
    return input;
}
bool comparison(string s1, string s2){
    int num1 = 0;
    for(int i=2;;i++){
        if(s1[i] >= '0' && s1[i] <= '9')
            num1 = num1*10 + (s1[i]-48);
        else
            break;
    }
    int num2 = 0;
    for(int i=2;;i++){
        if(s2[i] >= '0' && s2[i] <= '9')
            num2 = num2*10 + (s2[i]-48);
        else
            break;
    }
    return num1 < num2;
}
bool replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
int main(){
    int file_number;
    string url_substring;
    cout<<"Enter Leetcode File number: ";
    cin>>file_number;
    cout<<"Enter File name: ";
    getchar();
    getline(cin,url_substring);
    transform(url_substring.begin(),url_substring.end(),url_substring.begin(),::tolower);
    cout<<"The file name you entered is '"<<url_substring<<"'"<<endl;
    string difficulty_level;
    cout<<"Enter Difficulty Level (Easy, Medium, Hard): ";
    cin>>difficulty_level;
    string sol_url_substr = "";
    if(file_number < 10)
        sol_url_substr = "00"+to_string(file_number);
    else if(file_number < 100)
        sol_url_substr = "0"+to_string(file_number);
    else
        sol_url_substr = to_string(file_number);
    sol_url_substr += "-" + camel_case_converter(url_substring,1);
    string str_to_append = "\n|";
    str_to_append += to_string(file_number);
    str_to_append += "|[" + camel_case_converter(url_substring,0) + "](https://leetcode.com/problems/" + camel_case_converter(url_substring,1,1) + "/)|";
    if(file_number <= 500)
        str_to_append += "[<img src=\"images/github.svg\" width=\"27\" title=\"Solution\" />](https://github.com/yvrakesh/Leetcode/tree/main/code-0001-to-0499/";
    else if(file_number <= 999)
        str_to_append += "[<img src=\"images/github.svg\" width=\"27\" title=\"Solution\" />](https://github.com/yvrakesh/Leetcode/tree/main/code-0500-to-0999/";
    else if(file_number <= 1499)
        str_to_append += "[<img src=\"images/github.svg\" width=\"27\" title=\"Solution\" />](https://github.com/yvrakesh/Leetcode/tree/main/code-1000-to-1499/";
    else if(file_number <= 1999)
        str_to_append += "[<img src=\"images/github.svg\" width=\"27\" title=\"Solution\" />](https://github.com/yvrakesh/Leetcode/tree/main/code-1500-to-1999/";
    else if(file_number <= 2499)
        str_to_append += "[<img src=\"images/github.svg\" width=\"27\" title=\"Solution\" />](https://github.com/yvrakesh/Leetcode/tree/main/code-2000-to-2499/";
    else if(file_number <= 2999)
        str_to_append += "[<img src=\"images/github.svg\" width=\"27\" title=\"Solution\" />](https://github.com/yvrakesh/Leetcode/tree/main/code-2500-to-2999/";

    str_to_append += sol_url_substr + ")|";
    difficulty_level = camel_case_converter(difficulty_level,0);
    cout<<"Enter Company by Comma Space Seperation: ";
    string str1, str2;
    vector <string> c,v;
    string temp_str = "";
    getchar();
    getline(cin,str1);
    for(int i=0;i<str1.length();i++){
        if(str1[i] == ','){
            c.push_back(temp_str);
            i++;
            temp_str = "";
        }
        else
            temp_str += str1[i];
    }
    c.push_back(temp_str);
    for(auto i:c){
        str_to_append += "[<img src=\"images/"+i+".svg\" width=\"27\" title=\""+camel_case_converter(i,0)+"\" />](https://github.com/yvrakesh/Leetcode/tree/main/company/"+camel_case_converter(i,1)+")&nbsp; ";
    }
    str_to_append += "|";
    if(difficulty_level == "Medium")
        str_to_append += "[![Medium](images/MediumBlue.svg)](https://github.com/yvrakesh/Leetcode/tree/main/difficulty/Medium)|";
    else if(difficulty_level == "Hard")
        str_to_append += "[![Hard](images/HardRed.svg)](https://github.com/yvrakesh/Leetcode/tree/main/difficulty/Hard)|";
    else
        str_to_append += "[![Easy](images/EasyGreen.svg)](https://github.com/yvrakesh/Leetcode/tree/main/difficulty/Easy)|";
    cout<<"Enter Tags by Comma space seperation: ";
    getline(cin,str2);
    temp_str = "";
    for(int i=0;i<str2.length();i++){
        if(str2[i] == ','){
            v.push_back(temp_str);
            i++;
            temp_str = "";
        }
        else
            temp_str += str2[i];
    }
    v.push_back(temp_str);
    string time_comp, space_comp;
    cout<<"Enter Time Complexity: ";
    cin>>time_comp;
    str_to_append += "O(" + time_comp + ")";
    cout<<"Enter Space Complexity: ";
    cin>>space_comp;
    str_to_append += "|O(" + space_comp + ")|";
    for(int j = 0;j<v.size()-1;j++){
        auto i = v[j];
        str_to_append += "["+camel_case_converter(i,0)+"](https://github.com/yvrakesh/Leetcode/tree/main/tag/"+camel_case_converter(i,1)+"), ";
    }
    str_to_append += "["+camel_case_converter(v[v.size()-1],0)+"](https://github.com/yvrakesh/Leetcode/tree/main/tag/"+camel_case_converter(v[v.size()-1],1)+")";
    cout<<"String to append is "<<str_to_append<<endl;
    int flag;
    cout<<"Enter 0 to stop, anything else to proceed"<<endl;
    cin>>flag;
    if(!flag){
        cout<<"Terminating\n";
        return 0;
    }
    for(auto i:c){
        ofstream out;
        out.open("company/"+camel_case_converter(i,1)+"/README.md", ios::app);
        out<<str_to_append;
    }
    ifstream fin;
    fin.open("README.md");
    vector <string> readme_file;
    int i = 0;
    while(fin){
        string line;
        getline(fin, line);
        if(i++ > 6 && line.compare(""))
            readme_file.push_back("\n"+line);
    }
    readme_file.push_back(str_to_append);
    sort(readme_file.begin(),readme_file.end(),comparison);
    ofstream out1;
    out1.open("README.md",ios::trunc);
    out1<<"# Leetcode\nLeetcode Questions Practice\n\nClick on difficulty buttons (Easy, Medium, Hard) or Tags or company to filter that category problems only.\n\n|#|Title|Sol|Companies|Difficulty|Time|Space|Tags|\n| - | - | - | - | - |  - | - | - |";
    for(auto i:readme_file)
        out1<<i;
    // out1<<"|";
    // Updating tag folders
    for(auto i:v){
        ifstream fin1;
        fin1.open("tag/"+camel_case_converter(i,1)+"/README.md");
        vector <string> temp;
        int j = 0;
        while(fin1){
            string line;
            getline(fin1,line);
            if(j++ > 6 && line.compare(""))
                temp.push_back("\n"+line);
        }
        temp.push_back(str_to_append);
        sort(temp.begin(),temp.end(),comparison);
        ofstream out2;
        out2.open("tag/"+camel_case_converter(i,1)+"/README.md",ios::trunc);
        out2<<"# Leetcode\nLeetcode Questions Practice - "+camel_case_converter(i,0)+"\n\nClick on difficulty buttons (Easy, Medium, Hard) or Tags or company to filter that category problems only.\n\n|#|Title|Sol|Companies|Difficulty|Time|Space|Tags|\n| - | - | - | - | - |  - | - | - |";
        for(auto i:temp)
            out2<<i;
        // out2<<"|";
    }
    // Updating difficulty level folders
    ifstream fin1;
    fin1.open("difficulty/"+camel_case_converter(difficulty_level,0)+"/README.md");
    vector <string> temp;
    int j = 0;
    while(fin1){
        string line;
        getline(fin1,line);
        if(j++ > 6 && line.compare(""))
            temp.push_back("\n"+line);
    }
    temp.push_back(str_to_append);
    sort(temp.begin(),temp.end(),comparison);
    ofstream out2;
    out2.open("difficulty/"+camel_case_converter(difficulty_level,0)+"/README.md",ios::trunc);
    out2<<"# Leetcode\nLeetcode Questions Practice - "+camel_case_converter(difficulty_level,1)+"\n\nClick on difficulty buttons (Easy, Medium, Hard) or Tags or company to filter that category problems only.\n\n|#|Title|Sol|Companies|Difficulty|Time|Space|Tags|\n| - | - | - | - | - |  - | - | - |";
    for(auto i:temp)
       out2<<i;
    // out2<<"|";
    return 0;
}