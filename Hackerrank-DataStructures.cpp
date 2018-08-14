Array DS (C)
------------------------------------------------------
int main(){
    int n; 
    scanf("%d",&n);
    int *arr = malloc(sizeof(int) * n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    for(int i = (n - 1); i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    return 0;
}


2D Array DS (C)
--------------------------------------------------------
int main(){
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    int temp;
    int sum = -100;
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            temp = arr[i][j]+ arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1];
            if (temp > sum)
                sum = temp;
        }
    }
    printf("%d", sum);
    return 0;
}


Left Rotation (C++)
--------------------------------------------------------
int main() {
    int n, d, incrementer;
    scanf("%d %d\n", &n, &d);
    int array[n];
    int temp[n];
    d = d % n;
    for (int a = 0; a < n; a++) {
        scanf("%d", &array[a]);
    }     //////scans for array  
    incrementer = d; 
    for (int a = 0; a < n; a++) {   
        temp[a] = array[incrementer];
        //printf("%d %d\n", temp[a], array[incrementer]);
        incrementer = incrementer + 1;
        if (incrementer == n)
            incrementer = 0;
    } 
    for (int a = 0; a < n; a++) {
        printf("%d ", temp[a]);
    }    
    return 0;
}


Sparse Array (C)
--------------------------------------------------------
int main() {
    int N, Q;
    scanf("%d \n", &N);
    char N_strings[N][20];
    for (int a = 0; a < N; a++) {
        scanf("%s \n", N_strings[a]);
    }
    scanf("%d \n", &Q);
    char temp_word[20];
    int instances, test;
    for (int a = 0; a < Q; a++) {
        scanf("%s \n", temp_word);
        instances = 0;
        for (int b = 0; b < N; b++) {    ///looping thru the words of the list  
            //printf("%s %s %d\n", temp_word, N_strings[b], instances);
            if (strcmp(temp_word, N_strings[b]) == 0)
                instances = instances + 1;  
            //printf("%s %s %d\n", temp_word, N_strings[b], instances);
        }
        printf("%d\n", instances);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}


Print Elements of Linked List (C++)
--------------------------------------------------------
void Print(Node *head)
{
  Node * temp = head;
  while (temp != NULL) {
     printf("%d \n", temp->data);
     temp =  temp->next; 
  } 
}


Insert a Node at the Tail of a Linked List (C++)
--------------------------------------------------------
Node* Insert(Node *head,int data)
{
  Node *cur= new Node;  
   cur->data = data;  
   cur->next = NULL;  
   if(head==NULL){  
     head = cur;  
   }else{  
     Node *curr = new Node;  
     curr = head;  
     while(curr->next !=NULL){  
       curr = curr->next;  
     }  
     curr->next = cur;  
   }  
     return head; 
}


Insert a node at the head of a linked list (C++)
--------------------------------------------------------
Node* Insert(Node *head,int data)
{
  Node *new_head = new Node;
  new_head->data = data;  
  new_head->next = head;  
  Node *incrementer = new Node;
  incrementer = new_head;  
  while (incrementer->next != NULL) {
      incrementer = incrementer->next;
  }
  return new_head;
}


Insert a node at a specific position in a linked list (C++)
--------------------------------------------------------
Node* InsertNth(Node *head, int data, int position)
{
  Node *change = new Node;
  change->data = data;
  change->next = NULL;
  if(head==NULL){  
     head = change; 
     return head;
  }
  else if (position == 0) {
      change->next = head;
      return change;
  }
  else {
    Node *incrementer = new Node;  
    incrementer = head;
    for (int i = 0; i < (position - 1); i++) {
      incrementer = incrementer->next;
    }    
    change->next = incrementer->next;
    incrementer->next = change;
    return head;
  }
}

Delete a Node (C++)
--------------------------------------------------------
Node* Delete(Node *head, int position)
{
  if(head==NULL || (head->next == NULL && position == 0)){  
     return NULL;
  }
  Node *incrementer = new Node;
  incrementer = head;
  if (position == 0) {
      incrementer = incrementer->next;
      free(head);
      return incrementer;
  }
  for (int i = 0; i < (position - 1); i++) {
      incrementer = incrementer->next;
  }
  Node *deleted_node = new Node;
  deleted_node = incrementer->next;
  incrementer->next = deleted_node->next;
  free(deleted_node);
  return head;
}


Print in reverse (C++)
--------------------------------------------------------
void ReversePrint(Node *head)
{
   if (head == NULL) {
       return;
   }
   ReversePrint(head->next);
   printf("%d\n", head->data);
}



Cycle Detection (C++)
--------------------------------------------------------
bool has_cycle(Node* head) {
    Node *slow;
    Node *fast;
    slow = head;
    fast = head;
    while (slow != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }   
    return false;
}


Preorder Traversal (C++)
--------------------------------------------------------
void preOrder(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);   
    preOrder(root->left);
    preOrder(root->right);
}


Postorder Traversal (C++)
--------------------------------------------------------
void postOrder(node *root) {
    struct node *temp;
    temp=root;
    if(temp!=NULL)
      {  
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d ",temp->data);
    }
}


Inorder Traversal (C++)
--------------------------------------------------------
oid inOrder(node *root) {
    struct node *temp;
    temp=root;
    if (temp != NULL)
      {  
        inOrder(temp->left);
        printf("%d ",temp->data);
        inOrder(temp->right);
    }
}


Height of Binary Tree (C++)
--------------------------------------------------------
   int height(Node* root) {
        if (root == NULL) {
            return -1;
        } 
        return 1 + max(height(root->left), height(root->right)); 
    }

    int max(int a, int b) {
        if (a >= b) {
            return a;
        }
        return b;
    }
  
  
 Top View of Tree (C++)
  --------------------------------------------------------
  void print_left_side(node *root)
{
    if (root == NULL)
        return;
    print_left_side(root->left);
    printf("%d ", root->data);
}

void print_right_side(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    print_right_side(root->right);
}

void top_view(node *root)
{
    node *x;
    print_left_side(root);
    for (x=root; x->right!=NULL; x=x->right)
        printf("%d ", x->right->data);
    //print_right_side(root->right);
}

Binary Search Tree: Insert
--------------------------------------------------------
node * insert(node * root, int value)
{
   node *insertion;
   node *pre_temp;
   node *post_temp;
   insertion = (node *)malloc(sizeof(node));
   pre_temp = (node *)malloc(sizeof(node));
   post_temp = (node *)malloc(sizeof(node));
   post_temp = root;
   pre_temp = root;
   insertion->data = value;
   insertion->left = NULL;
   insertion->right = NULL;
   if (root == NULL) 
      return insertion;
   while (post_temp != NULL) {
       pre_temp = post_temp;
       if (value < pre_temp->data) {
            post_temp = pre_temp->left;
       } else if (value > pre_temp->data) {
            post_temp = pre_temp->right;
       }
   }
   if (value > pre_temp->data) {
       pre_temp->right = insertion;
   }
    else if (value < pre_temp->data) {
       pre_temp->left = insertion;
    }
   return root;
}


Tree: Huffman Decoding 
--------------------------------------------------------
void decode_huff(node * root,string s)
{
    node *temp;
    temp = root;
    for (int q = 0; s[q] == '1' || s[q] == '0'; q++) {
        if (s[q] == '0') {
            temp = temp->left;
        } else if (s[q] == '1') {
            temp = temp->right;
        }
        if (temp->data != '\0') {
            printf("%c", temp->data);
            temp = root;
        }
    }
    
}


Binary Search Tree : Lowest Common Ancestor
--------------------------------------------------------
node * lca(node * root, int v1,int v2)
{   
    if (root == NULL) return NULL;
 
    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > v1 && root->data > v2)
        return lca(root->left, v1, v2);
 
    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->data < v1 && root->data < v2)
        return lca(root->right, v1, v2);
 
    return root;
}


Maximum Element
--------------------------------------------------------
int main() {
    stack<int> q;
    stack<int> max;
    int lines, command, push_element, temp;
    scanf("%d\n", &lines);
    int stack[lines];
    int top = -1;
    for (int a = 0; a < lines; a++) {
        scanf("%d ", &command);
        if (command == 1) {
            scanf("%d", &push_element);
            q.push(push_element);
            if (max.empty() || push_element >= max.top()) {
                max.push(push_element);
            }
        } else if (command == 2) {
            if (max.top() == q.top()) {
                max.pop();
            }
            q.pop();
        } else if (command == 3) {
            printf("%d\n", max.top());
        }
        scanf("\n");
    }
    
    return 0;
}


Balancing Brackets
--------------------------------------------------------
string isBalanced(string s) {
    stack<char> st;  
    
    for (auto c: s) {
        switch (c) {
            case '{':
            case '(':
            case '[':
                st.push(c);
                break;
            case '}':
                if (st.empty() || (st.top() != '{')) {
                    return "NO";
                }
                st.pop();
                break;
            case ')':
                if (st.empty() || (st.top() != '(')) {
                    return "NO";
                }
                st.pop();
                break;
            case ']':
                if (st.empty() || (st.top() != '[')) {
                    return "NO";
                }
                st.pop();
                break;
        }
    }
    
    return st.empty() ? "YES" : "NO";
}



