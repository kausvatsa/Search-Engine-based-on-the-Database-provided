// Do NOT add any other includes
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Dict
{
private:
/*
    class AVL_treenode
    {
    public:
        string key;
        int height;
        int count = 0;

        AVL_treenode *par;
        AVL_treenode *left;
        AVL_treenode *right;

        AVL_treenode() { par = left = right = NULL; }
        AVL_treenode(string k)
        {
            key = k;

            par = right = left = NULL;
        }

        int hit(AVL_treenode *root)
        {
            if (root == NULL)
            {
                return -1;
            }
            else
            {
                return 1 + max(hit(root->left), hit(root->right));
            }
        }

        AVL_treenode *LeftLeftRotation()
        {
            AVL_treenode *root = par;
            AVL_treenode *y = par->right;
            AVL_treenode *z = par->right->left;

            root->right = z;
            y->left = root;
            par = y;

            root->height = hit(root);

            y->height = hit(y);
            return y;
        }

        AVL_treenode *RightRightRotation()
        {

            AVL_treenode *root = par;
            AVL_treenode *y = par->left;
            AVL_treenode *z = par->left->right;

            root->left = z;
            y->right = root;
            par = y;
            root->height = hit(root);

            y->height = hit(y);
            return y;
        }

        AVL_treenode *LeftRightRotation()
        {
            AVL_treenode *root = par;
            AVL_treenode *y = par->left;
            AVL_treenode *z = par->left->right;

            root->left = z->right;
            y->right = z->left;
            z->left = y;
            z->right = root;
            par = z;
            root->height = hit(root);

            y->height = hit(y);
            z->height = hit(z);
            return z;
        }

        AVL_treenode *RightLeftRotation()
        {
            AVL_treenode *root = par;
            AVL_treenode *y = par->right;
            AVL_treenode *z = par->right->left;

            root->right = z->left;
            y->left = z->right;
            z->left = root;
            z->right = y;
            par = z;
            root->height = hit(root);

            y->height = hit(y);
            z->height = hit(z);
            return z;
        }

        ~AVL_treenode()
        {
            //left = right = par = NULL;
            
        }
    };
    
    class AVL_TREE
    {
    private:
        int size;
        AVL_treenode *root;

    public:
        AVL_TREE()
        {
            size = 0;
            root = nullptr;
        }
        ~AVL_TREE()
        {
            size = 0;
            root = nullptr;
        }

        int ht(AVL_treenode *root)
        {
            if (root == NULL)
            {
                return -1;
            }

            else
            {
                return 1 + max(ht(root->left), ht(root->right));
            }
        }

        void insert(string k){
       
                if (root == NULL)
                {
                    AVL_treenode *newnode = new AVL_treenode(k);
                    size++;

                    root = newnode;
                    root->count = 1;
                }
                else if (root->key == k){
                    int n = root->count;
                    n++;
                    root->count = n;
                }
                else if (root->key > k)
                {

                    AVL_TREE *temps = new AVL_TREE();

                    temps->root = root->left;

                    temps->insert(k);
                    root->left = temps->root;

                    delete temps;
                    size++;
                }

                else if (root->key < k)
                {
                    AVL_TREE *temps = new AVL_TREE();
                    temps->root = root->right;

                    temps->insert(k);
                    root->right = temps->root;

                    delete temps;
                    size++;
                }

                // root->height = ht(root);
                // if (ht(root->left) - ht(root->right) > 1 || ht(root->left) - ht(root->right) < -1)
                // {
                //     if (ht(root->left) - ht(root->right) > 1)
                //     {

                //         if (k < root->left->key)
                //         {

                //             root->par = root;
                //             root = root->RightRightRotation();

                //             root->par = NULL;
                //         }
                //         else
                //         {

                //             root->par = root;
                //             root = root->LeftRightRotation();

                //             root->par = NULL;
                //         }
                //     }
                //     else
                //     {

                //         if (k > root->right->key)
                //         {

                //             root->par = root;
                //             root = root->LeftLeftRotation();

                //             root->par = NULL;
                //         }
                //         else
                //         {

                //             root->par = root;
                //             root = root->RightLeftRotation();

                //             root->par = NULL;
                //         }
                //     }
                // }
            }
        
        int search(string k)
        {
            if (root == NULL)
            {
                return 0;
            }
            else
            {
                if (root->key == k)
                {
                    return root->count;
                }

                else if (root->key > k)
                {
                    if (root->left == NULL)
                    {
                        return 0;
                    }
                    else if (root->left->key == k)
                    {
                        // std::cout << "hi" << endl;
                        return root->left->count;
                    }
                    else
                    {
                        AVL_TREE *temps = new AVL_TREE();
                        temps->root = root->left;
                        return temps->search(k);
                        delete temps;
                    }
                }

                else
                {
                    if (root->right == NULL)
                    {
                        return 0;
                    }
                    else if (root->right->key == k)
                    {
                        return root->right->count;
                    }

                    else
                    {
                        AVL_TREE *temps = new AVL_TREE();
                        temps->root = root->right;
                        return temps->search(k);

                        delete temps;
                    }
                }
            }
        }

        int get_size()
        {
            return size;
        }

        AVL_treenode *get_root()
        {
            return root;
        }
    };

    AVL_TREE* tree = new AVL_TREE();
*/
    vector<string> dataString;
    // for (int i =0; i<45;i++) dataString.push_back({});
    class Trienode{
        public:
        vector<Trienode*> arr;
        long long  eofw;
        string val;
        long long id;
        Trienode(){
            for(int i = 0; i<200; i++){
                arr.push_back(nullptr);
            }
            eofw = 0;val = "";
            id = -1;
        }
    };

    class Trie{
        private: 
        Trienode* root; 
        public:
        Trie(){
            root = new Trienode();
        }
        void insert(string key,vector<string> &dataString){
            // cout<<key<<" ";
            Trienode * temp = root;
            int index;
            for (int i = 0; i<key.size(); i++){
                index = int(key[i]);
                if (temp->arr[index] == nullptr){
                    temp->arr[index] = new Trienode();
                }
                temp = temp->arr[index];
            }
            
            temp->eofw = temp->eofw +1;
            temp->val = key;
            // cout<<temp->eofw<<endl;
            if (temp->id == -1){
                string t = key + ", " + to_string(temp->eofw);
                dataString.push_back(t) ;     
                temp->id = dataString.size() -1 ;      
            }
            else if (temp->id!=-1){
                string t = key + ", " + to_string(temp->eofw);
                dataString[temp->id]= t;
            }
            
        }
        int search(string key){
            Trienode * temp = root;
            int index;
            for (int i = 0; i<key.size(); i++){
                index = int(key[i]);
                if (temp->arr[index] == nullptr){
                    return 0;
                }
                temp = temp->arr[index];
            }
            return temp->eofw;
        }

        Trienode * get_root(){
            return root;
        }
        
    };

     Trie* tree = new Trie();

    //void helper_dump(AVL_treenode* root, string filename);
   void helperDump(string filename, vector<string>&v);
public:
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};