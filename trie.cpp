#include <bits/stdc++.h>
using namespace std;


struct trie
{


    trie* A[26];
    bool isLeaf;
    string meaning;

};

trie* root=NULL;

trie* getnode()
{
    trie* temp=new trie;

    for(int i=0; i<26; i++)
    {
        temp->A[i]=NULL;
    }

    temp->isLeaf = false;
    temp->meaning = "";

    return temp;

}

void ins(string S, string m)
{
    int Z=S.size();

    trie* temp=root;


    for(int i=0; i<Z; i++)
    {
        if(root==NULL)
        {

            root=getnode();
            temp=root;
        }

         if(!temp->A[S[i]-97])
            {
                temp->A[S[i]-97]=getnode();

            }
            temp=temp->A[S[i]-97];

    }

    temp->isLeaf = true;
    temp->meaning = m;
}

string lookup(string S)
{


    trie* temp=root;

    int Z=S.size();

    for(int i=0; i<Z; i++)
    {
        if(temp->A[S[i]-97])
        {

            temp=temp->A[S[i]-97];

        }
        else
        {
            return "Not found";
        }
    }

    if(temp->isLeaf) {
            return temp->meaning;
    } else {
            return "Not found";
    }





}

bool isEmpty(trie* root) {

        if(!root) return true;
        for(int i = 0; i < 26; i++) {
                if(root->A[i]) return false;
        }

        return true;
}

trie* rem(trie* root, string key, int depth) {

        if(!root) return NULL;

        if(key.size() == depth) {

                    root->isLeaf = false;
                    root->meaning = "";

                    if(isEmpty(root)) {
                            delete(root);
                            return NULL;
                    }

                    return root;
        }

        root->A[key[depth] - 'a'] = rem(root->A[key[depth] - 'a'], key, depth + 1);

        if(isEmpty(root)) {
                delete(root);
                return NULL;
        }

        return root;


}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        cout << endl << endl;
        cout << "///////////********* DICTIONARY USING TRIE *************/////////////" << endl;
        cout << endl << endl;


        ins("come", "to move toward someone or something");
        ins("native", "born in a particular place");
        ins("home", " the place (such as a house or apartment) where a person lives");
        ins("radiation", "a type of dangerous and powerful energy that is produced by radioactive substances and nuclear reactions");
        ins("incite", "to cause (someone) to act in an angry, harmful, or violent way");
        ins("go", "to move or travel to a place");
        ins("inevitable", "sure to happen");
        ins("agriculture", "the science or occupation of farming");
        ins("anguish", "extreme suffering, grief, or pain");
        ins("abandon", "to leave and never return to (someone who needs protection or help)");
        ins("address", "to write on an envelope, package, letter, etc., the name and address of the person or business it is being sent to");


        string word, meaning;
        string ans;
         char now = 'y';
         int choice;




    do
	{

		cout << "1. Insert "<< endl;
		cout <<"2. Search " << endl;
		cout << "3. Remove " << endl;
		cout <<"Enter your choice" << endl;
		cin >> choice;
		if(choice == 1) {

                    cout << "Enter word:  "<< endl;
                     cin >> word;
                    cout << "Enter meaning:  " << endl;
                    cin.ignore();
                    getline(cin, meaning);
                    ins(word, meaning);

                    cout << word << " is added to dictionary" << endl;
                     cout << "\n Enter y to continue or n to exit" << endl;
                    cin >> now;
                    cout << endl;

		} else if(choice == 2) {




                    cout << "Enter word to be searched:" << endl;
                    cin >> word;
                    ans = lookup(word);
                     if(ans == "Not found") {
                            cout << ans << endl;
                     } else {
                            cout << word << "   :   ";
                            cout << lookup(word) << endl;
                     }

                      cout << "\n Enter y to continue or n to exit" << endl;
                    cin >> now;
                    cout << endl;



            } else if(choice == 3) {


                    cout << "Enter word to be remove" << endl;
                    cin >> word;
                    rem(root, word, 0);

                     cout << "\n Enter y to continue or n to exit" << endl;
                    cin >> now;
                    cout << endl;


            }





	} while (now == 'y');

	cout << "Thank You Very Much" << endl;




    return 0;
}
