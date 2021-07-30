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
        sol_url_substr = "000"+to_string(file_number);
    else if(file_number < 100)
        sol_url_substr = "00"+to_string(file_number);
    else if(file_number < 1000)
        sol_url_substr = "0" + to_string(file_number);
    else
        sol_url_substr = to_string(file_number);
    sol_url_substr += "-" + camel_case_converter(url_substring,1);
    string str_to_append = "\n|";
    str_to_append += to_string(file_number);
    str_to_append += "|[" + camel_case_converter(url_substring,0) + "](https://leetcode.com/problems/" + camel_case_converter(url_substring,1,1) + "/)|";
    str_to_append += "[<img src=\"https://edent.github.io/SuperTinyIcons/images/svg/github.svg\" width=\"27\" title=\"Solution\" />](https://github.com/yvrakesh/Leetcode/tree/main/code/";
    str_to_append += sol_url_substr + ")|";
    difficulty_level = camel_case_converter(difficulty_level,0);
    str_to_append += "[<img src=\"https://edent.github.io/SuperTinyIcons/images/svg/amazon.svg\" width=\"27\" title=\"Amazon\" />](https://github.com/yvrakesh/Leetcode/tree/main/company/Amazon)|";
    if(difficulty_level == "Medium")
        str_to_append += "[![Medium](https://img.shields.io/badge/-Medium-darkgreen)](https://github.com/yvrakesh/Leetcode/tree/main/difficulty/Medium)|";
    else if(difficulty_level == "Hard")
        str_to_append += "[![Hard](https://img.shields.io/badge/-Hard-darkred)](https://github.com/yvrakesh/Leetcode/tree/main/difficulty/Hard)|";
    else
        str_to_append += "[![Easy](https://img.shields.io/badge/-Easy-blue)](https://github.com/yvrakesh/Leetcode/tree/main/difficulty/Easy)|";
    cout<<"Enter Tags by ', ' seperation: ";
    getchar();
    string str;
    getline(cin,str);
    vector <string> v;
    string temp_str = "";
    for(int i=0;i<str.length();i++){
        if(str[i] == ','){
            v.push_back(temp_str);
            i++;
            temp_str = "";
        }
        else
            temp_str += str[i];
    }
    v.push_back(temp_str);
    for(auto i:v)
            str_to_append += "["+camel_case_converter(i,0)+"](https://github.com/yvrakesh/Leetcode/tree/main/tag/"+camel_case_converter(i,1)+"), ";
    replace(str_to_append,", |","|");
    float acpt_percent, like_percent;
    int likes, dislikes;
    cout<<"Enter Acceptance Percentage: ";
    cin>>acpt_percent;
    getchar();
    cout<<"Enter Likes : ";
    cin>>likes;
    cout<<"Enter Dislikes : ";
    cin>>dislikes;
    like_percent = ((float)(likes*100))/(likes+dislikes);
    char str_temp[100];
    sprintf(str_temp, "|%.1f%%|%.1f%%|", acpt_percent,like_percent);
    str_to_append += str_temp;
    cout<<"String to append is "<<str_to_append<<endl;
    ofstream out;
    out.open("company/Amazon/README.md", ios::app);
    out<<str_to_append;
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
    out1<<"# Leetcode\nLeetcode Questions Practice\n\nClick on difficulty buttons (Easy, Medium, Hard) or Tags or company to filter that category problems only.\n\n|#|Title|Sol|Companies|Difficulty|Tags|Accptce|Likes|\n| - | - | - | - | - |  - | - | - |";
    for(auto i:readme_file)
        out1<<i;
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
        out2<<"# Leetcode\nLeetcode Questions Practice - "+camel_case_converter(i,0)+"\n\nClick on difficulty buttons (Easy, Medium, Hard) or Tags or company to filter that category problems only.\n\n|#|Title|Sol|Companies|Difficulty|Tags|Accptce|Likes|\n| - | - | - | - | - |  - | - | - |";
        for(auto i:temp)
            out2<<i;
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
    out2<<"# Leetcode\nLeetcode Questions Practice - "+camel_case_converter(difficulty_level,1)+"\n\nClick on difficulty buttons (Easy, Medium, Hard) or Tags or company to filter that category problems only.\n\n|#|Title|Sol|Companies|Difficulty|Tags|Accptce|Likes|\n| - | - | - | - | - |  - | - | - |";
    for(auto i:temp)
        out2<<i;
    return 0;
}