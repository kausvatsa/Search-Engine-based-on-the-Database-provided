// Do NOT add any other includes
#include "dict.h"
using namespace std;

Dict::Dict()
{
   
}


void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    int n = sentence.size();
    int m = 0;
    int k = n;
    string s = " .,-:!'()?—[]“”‘’˙;@\"";

    // removed leading seps
    for (int i = 0; i < n; i++)
    {
        if (s.find(sentence[i]) != string::npos)
        {
            continue;
        }
        else
        {
            m = i;
            break;
        }
    }

    // removed trailing seps
    for (int i = n - 1; i >= 0; i--)
    {

        if (s.find(sentence[i]) != string::npos)
        {
            continue;
        }
        else
        {
            k = i;
            break;
        }
    }
    // cout<<sentence[k]<<endl;
    // cout<<sentence.substr(m,k-m+1)<<"\n";
    //  string new_s = "";//creating a new string
    // int start = m;
    // int end = k;
    string subs = "";

    for (int j = m; j <= k; j++)
    {
        if ((int(sentence[j]) >= 65) && (int(sentence[j]) <= 90))
        {
            // char(int(sentence[j]+32))
            subs.push_back(char(int(sentence[j] + 32)));
        }
        else if (s.find(sentence[j]) != string::npos)
        {
            if (subs != "")
            {
                // cout << subs << "\n";
                tree->insert(subs,dataString);
                //tree1->insert(subs);
            }
            subs = "";
        }
        else
        {
            subs.push_back(sentence[j]);
        }
    }
    if (subs != "")
    {
        tree->insert(subs,dataString);
        //tree1->insert(subs);
    }
   
}

// void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
// {
//     string s = "";
//     for (int i = 0; i < sentence.size(); i++)
//     {
//         if ((int(sentence[i]) >= 65) && (int(sentence[i]) <= 90))
//         {
//             // char(int(sentence[j]+32))
//             s.push_back(char(int(sentence[i] + 32)));
//         }
// else if (sentence[i]==' '||sentence[i]=='.'||sentence[i]==','||sentence[i]=='-'||sentence[i]==':'||sentence[i]=='!'||sentence[i]=='"'||sentence[i]=='\''||sentence[i]=='('||sentence[i]==')'||sentence[i]=='?'||sentence[i]=='['||sentence[i]==']'||sentence[i]==';'||sentence[i]=='@')       
//  {
//             tree->insert(s);
//             s.clear();
//         }
//         else
//         {
//             s.push_back(sentence[i]);
//         }
//         // else{
//         //     s.push_back('a');
//         //  }
//     }
// }

int Dict::get_word_count(string word)
{

    return tree->search(word);
}

void Dict::helperDump(string filename, vector<string> &v)
{
    
        ofstream file;
        file.open(filename, std::ios::app);

        for (long long i = 0;i<v.size();i++){
            file << v[i]<< endl;
        }
        file.close();
        
}


void Dict::dump_dictionary(string filename)
{
    //Implement your function here
    ofstream final;
    final.open(filename);

    helperDump(filename, dataString);

    final.close();
}

Dict::~Dict()
{
    dataString.clear();
    
}

// int main()
// {
//     // vector<string> vec2 = seperator("   VoL.1: 1884 30 NOVEMBER, 1896 1  ");//VOL.1: 1884 30 NOVEMBER, 1896 1
//     // for (int i = 0; i<vec2.size();i++){
//     //     cout<<vec2[i]<<"\n";
//     // }
//     Dict d;
//     d.insert_sentence(1, 8, 3, 10, "anchor lawda lasun lawda.");
//     cout<<d.get_word_count("anchor");
//     d.dump_dictionary("bellow.txt");
//     //cout << "hi" << endl;
// }