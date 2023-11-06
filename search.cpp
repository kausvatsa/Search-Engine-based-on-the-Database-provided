// Do NOT add any other includes
#include "search.h"

SearchEngine::SearchEngine()
{
    // Implement your function here
}

SearchEngine::~SearchEngine()
{
    // Implement your function here
    for (Node *node : dataNode)
    {
        delete node;
    }
    dataNode.clear();
    dataString.clear();
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    // Implement your function here

    dataString.push_back(sentence);
    Node *temp = new Node(book_code, page, paragraph, sentence_no, -1);
    dataNode.push_back(temp);
}

void match(string pattern, string sentence, vector<int> cont, vector<Node *> &ans, Node *SR, int &matches)
{
    int j = pattern.size() - 1;
    int i = j;
    while (i < sentence.size())
    {
        // cout<<pattern<<endl;

        if (j == 0 && (pattern[j] == sentence[i] || pattern[j] == char(int(sentence[i] + 32))))
        {
            ans.push_back(new Node(SR->book_code, SR->page, SR->paragraph, SR->sentence_no, i));
            i = i + pattern.size();
            j = pattern.size() - 1;
            matches++;
            
        }
        
        else if (pattern[j] == sentence[i] || pattern[j] == char(int(sentence[i] + 32)))
        {
            i--;
            j--;
            // cout<<"i: "<<i<<" pattern char: "<< pattern[j]<<" sentence char: "<<sentence[i]<<" j: "<<j<<endl;
            
        }
        // cout<<i<<", "<<j<<endl;
        // if (i==39){
        //             break;
        //         }
        else
        {
            if (int(sentence[i]) >= 65 && int(sentence[i]) <= 90)
            {
                char s = char(int(sentence[i] + 32));
               if (cont[s] >j)
                {
                    int k = j;
                    while (pattern[k] != s && k >= 0)
                    {
                        k--;
                    }
                    i = i + pattern.size() - k - 1;
                    j = pattern.size() - 1;
                }
                else
                {
                    // cout<<cont[s]<<endl;
                    i = i + pattern.size() - cont[s] - 1;
                    j = pattern.size() - 1;
                    // cout<<i<<", "<<j<<endl; 
                }
            }
            else
            {
                // cout<<"i: "<<i<<" pattern char: "<< pattern[j]<<" sentence char: "<<sentence[i]<<" j: "<<j<<endl;
                // cout<<sentence<<endl;
                
                if (cont[sentence[i]] >j)
                {
                    int k = j;
                    while (pattern[k] != sentence[i] && k >= 0)
                    {
                        k--;
                    }
                    i = i + pattern.size() - k - 1;
                    j = pattern.size() - 1;
                }
                else
                {
                    // cout<<cont[sentence[i]]<<endl;
                    i = i + pattern.size() - cont[sentence[i]] - 1;
                    j = pattern.size() - 1;
                    // cout<<i<<", "<<j<<endl;
                }
                
            }
            
        }
        
    }
}
Node *SearchEngine::search(string pattern, int &n_matches)
{
    // Implement your function here
    string s = "";
    for (int i = 0; i < pattern.size(); i++)
    {
        if (int(pattern[i]) >= 65 && int(pattern[i]) <= 90)
        {
            s.push_back(char(int(pattern[i] + 32)));
        }
        else
            s.push_back(pattern[i]);
    }
    vector<Node *> result;
    vector<int> container;
    help(s, container);
    for (long long  i = 0; i < dataString.size(); i++)
    {
        match(s, dataString[i], container, result, dataNode[i], n_matches);
    }
    if (n_matches == 0)
        return nullptr;
    result[0]->left = nullptr;
    result[0]->right = result[1];
    for (int i = 1; i < result.size() - 1; i++)
    {
        result[i]->left = result[i - 1];
        result[i]->right = result[i + 1];
    }
    result[result.size() - 1]->left = result[result.size() - 2];
    result[result.size() - 1]->right = nullptr;

    return result[0];
}

// int main(){
// // ('1', 0, 0, 1, 0) VOL.1: 1884 30 NOVEMBER, 1896 1
// // ('1', 0, 1, 2, 32) 1. A CONFESSION 1
// // ('1', 0, 2, 3, 50) [1884] I wrote it on a slip of paper and handed it to him myself.
// // ('1', 0, 2, 4, 116) In this note not only did I confess my guilt, but I asked adequate punishment for it, and closed with a request to him not to punish himself for my offence.
// // ('1', 0, 2, 5, 273) I also pledged myself never to steal in future.
// // ('1', 0, 3, 6, 321) An Autobiography, Pt. I, Ch. VIII
// // ('1', 0, 4, 7, 355) 2. SPEECH AT ALFRED HIGH SCHOOL, RAJKOT 3
// // ('1', 0, 5, 8, 397) July 4, 1888 I hope that some of you will follow in my footsteps, and after you return from England you will work wholeheartedly for big reforms in India.
// // ('1', 0, 6, 9, 552) [From Gujarati] Kethiawar Times, 12 7 1888
// // ('1', 0, 7, 10, 595) 1 When Gandhiji was 15, he had removed a bit of gold from his brother’s armlet to clear a small debt of the latter.
// // ('1', 0, 7, 11, 711) He felt so mortified about his act that he decided to make a confession to his father.
// // ('1', 0, 7, 12, 798) Parental forgiveness was granted to him in the form of silent tears.
// // ('1', 0, 7, 13, 867) The incident left a lasting mark on his mind.
//     SearchEngine* s = new SearchEngine();
//     s->insert_sentence(1,2,3,4,"I love you very much and you are an idiot.");
//     s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     s->insert_sentence( 0, 2, 3, 50,"[1884] I wrote it on a slip of paper and handed it to him myself.");
//     s->insert_sentence( 0, 2, 4, 116,"In this note not only did I confess my guilt, but I asked adequate punishment for it, and closed with a request to him not to punish himself for my offence.");
//     s->insert_sentence( 0, 2, 5, 273, "I also pledged myself never to steal in future.");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");

//     int match = 0;
//     Node* temp = s->search("I",match);
//     // cout<<temp->sentence_no<<endl;
//     while(temp){

//         cout<<temp->sentence_no<<endl;
//         temp = temp->right;
//     }
//     // cout<<s->search("a",match)->right->offset<<endl;
// }

// int main()
// {
//     // ('1', 0, 0, 1, 0) VOL.1: 1884 30 NOVEMBER, 1896 1
//     // ('1', 0, 1, 2, 32) 1. A CONFESSION 1
//     // ('1', 0, 2, 3, 50) [1884] I wrote it on a slip of paper and handed it to him myself.
//     // ('1', 0, 2, 4, 116) In this note not only did I confess my guilt, but I asked adequate punishment for it, and closed with a request to him not to punish himself for my offence.
//     // ('1', 0, 2, 5, 273) I also pledged myself never to steal in future.
//     // ('1', 0, 3, 6, 321) An Autobiography, Pt. I, Ch. VIII
//     // ('1', 0, 4, 7, 355) 2. SPEECH AT ALFRED HIGH SCHOOL, RAJKOT 3
//     // ('1', 0, 5, 8, 397) July 4, 1888 I hope that some of you will follow in my footsteps, and after you return from England you will work wholeheartedly for big reforms in India.
//     // ('1', 0, 6, 9, 552) [From Gujarati] Kethiawar Times, 12 7 1888
//     // ('1', 0, 7, 10, 595) 1 When Gandhiji was 15, he had removed a bit of gold from his brother’s armlet to clear a small debt of the latter.
//     // ('1', 0, 7, 11, 711) He felt so mortified about his act that he decided to make a confession to his father.
//     // ('1', 0, 7, 12, 798) Parental forgiveness was granted to him in the form of silent tears.
//     // ('1', 0, 7, 13, 867) The incident left a lasting mark on his mind.
//     SearchEngine *s = new SearchEngine();
//     s->insert_sentence(1, 3, 11, 2217, " [1884] I wrote it on a slip of paper and handed it to him myself.");
//     // s->insert_sentence(0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence(0, 2, 3, 50, "[1884] I wrote it on a slip of paper and handed it to him myself.");
//     // s->insert_sentence(0, 2, 4, 116, "In this note not only did I confess my guilt, but I asked adequate punishment for it, and closed with a request to him not to punish himself for my offence.");
//     // s->insert_sentence(0, 2, 5, 273, "I also pledged myself never to steal in future.");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // s->insert_sentence( 0, 0, 1, 0, "VOL.1: 1884 30 NOVEMBER, 1896 1");
//     // string shoo = "I would not have been anxious if you did not have my address.";
//     // cout<<shoo[51]<<endl;
//     int match = 0;
//     Node *traversal = s->search("and", match);
//     // cout<<traversal->sentence_no<<endl;
//     while (traversal)
//     {

//         cout << "in book " << traversal->book_code << " in page " << traversal->page << " in para " << traversal->paragraph << " in sentence " << traversal->sentence_no << " at " << traversal->offset << endl;
//         traversal = traversal->right;
//     }
//     cout << match << endl;
//     // cout << s->search("a", match)->right->offset << endl;
// }
