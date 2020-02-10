#include <iostream>
#include <cmath>
 
using namespace std;

const int COUNT = 20;
 
typedef struct bin_tree_node
{
        char v;
        struct bin_tree_node *left;
        struct bin_tree_node *right;
} BTNode;
 
BTNode *create_bin_tree_node(char v)
{
    BTNode *p = new BTNode;
 
    if (p != NULL)
    {
        p->v = v;
        p->left = NULL;
        p->right = NULL;
    }
 
    return p;
}
 
void create_balanced_bin_tree(BTNode **root, char arr[], int start, int end)
{
    if (start <= end)
    {
        int mid = (start + end + 1) / 2;
 
        *root = create_bin_tree_node(arr[mid]);
        create_balanced_bin_tree(&((*root)->left), arr, start, mid - 1);
        create_balanced_bin_tree(&((*root)->right), arr, mid + 1, end);
    }
}
 
void print_bin_tree(BTNode *root)
{
    if (root != NULL)
    {
        cout << root->v;
        print_bin_tree(root->left);
        print_bin_tree(root->right);
    }
}
void print_bin_tree1(BTNode *root)
{
    if (root != NULL)
    {
        print_bin_tree1(root->left);
        cout << root->v;
        print_bin_tree1(root->right);
    }
}

// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void print2DUtil(BTNode *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->v<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print2D(BTNode *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  
 
int main(int argc, char* argv[])
{
    char arr[20]="r'u eoaerlYc yul.et";
    BTNode *root = NULL;
    create_balanced_bin_tree(&root, arr, 0, 19);
    cout << "To whom it may concern,\n\n";
    cout << "I just wanted to give you this tree:\n";
    print2D(root);
    cout << "And it says inside:\n";
    print_bin_tree(root);
    cout << "\n\n";

    /* Heart message */
    // initializing variables and size 
    double a, b, n = 10; 
    string binCode = "01001001001000000110110001101111011101100110010100100000011110010110111101110101";
    int binCodeSize = binCode.size();
    int binCodeId = 0;
    
    // initializing String to print in heart 
    string message = " Happy Valentines Day <3 "; 
    
    // Position from where from top 
    // message box would be placed. 
    int print_message = 4; 
    
    // add space if message length is odd 
    if (message.length() % 2 != 0) 
        message += " "; 
    
    // outer loop to adjust length of upper 
    // part message is not handled in this part 
    for (a = 0; a < n; a++) { 
    
        // to print space and variable accordingly 
        for (b = 0; b <= 4 * n; b++) { 
    
        // computing distance to print variable 
        double distance1 = sqrt(pow(a - n, 2) + pow(b - n, 2)); 
        double distance2 = sqrt(pow(a - n, 2) + pow(b - 3 * n, 2)); 
    
        if (distance1 < n + 0.5 || distance2 < n + 0.5) {
            cout << binCode[binCodeId];
            binCodeId++;
            if(binCodeId == binCodeSize)
                binCodeId = 0;
        } else
            cout << " "; 
        } 
    
        // ending line after each iteration 
        cout << "\n"; 
    } 
    
    // printing the message part 
    // and lower part of heart. 
    // outer loop handles 
    // depth of the heart. 
    for (a = 1; a < 2 * n; a++) { 
    
        // for getting the lower curve of heart 
        for (b = 0; b < a; b++) 
        cout << " "; 
    
        // inner loop 
        // handles the message and spaces accordingly 
        for (b = 0; b < 4 * n + 1 - 2 * a; b++) { 
    
        // checks if the height is in range of message 
        // space 
        if (a >= print_message - 1 && a <= print_message + 1) { 
            int point = b - (4 * n - 2 * a - message.size()) / 2; 
    
            // prints message after leaving appropriate space 
            if (point < message.size() && point >= 0) { 
            if (a == print_message) 
                cout << message[point]; 
            else
                cout << " "; 
            } 
    
            else {
                cout << binCode[binCodeId];
                binCodeId++;
                if(binCodeId == binCodeSize)
                    binCodeId = 0;
            }
        } else {
            cout << binCode[binCodeId];
            binCodeId++;
            if(binCodeId == binCodeSize)
            binCodeId = 0;
        }
    } 
    
        cout << endl; 
    } 

    return 0;

}
