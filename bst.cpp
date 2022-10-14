#include <bits/stdc++.h>
using namespace std;

struct BST

{

    int data;

    struct BST *left;

    struct BST *right;
};

typedef struct BST NODE;

NODE *node;

NODE *createtree(NODE *node, int data)

{

    if (node == NULL)

    {

        NODE *temp;

        temp = (NODE *)malloc(sizeof(NODE));

        temp->data = data;

        temp->left = temp->right = NULL;

        return temp;
    }

    if (data < (node->data))

    {

        node->left = createtree(node->left, data);
    }

    else if (data > node->data)

    {

        node->right = createtree(node->right, data);
    }

    return node;
}

NODE *search(NODE *node, int data)

{

    if (node == NULL)

        printf("\nElement not found");

    else if (data < node->data)

    {

        node->left = search(node->left, data);
    }

    else if (data > node->data)

    {

        node->right = search(node->right, data);
    }

    else

        printf("\nElement found is: %d", node->data);

    return node;
}

void inorder(NODE *node)

{

    if (node != NULL)

    {

        inorder(node->left);

        printf("%d\t", node->data);

        inorder(node->right);
    }
}

void preorder(NODE *node)

{

    if (node != NULL)

    {

        printf("%d\t", node->data);

        preorder(node->left);

        preorder(node->right);
    }
}

void postorder(NODE *node)

{

    if (node != NULL)

    {

        postorder(node->left);

        postorder(node->right);

        printf("%d\t", node->data);
    }
}

NODE *findMin(NODE *node)

{

    if (node == NULL)

    {

        return NULL;
    }

    if (node->left)

        return findMin(node->left);

    else

        return node;
}

NODE *del(NODE *node, int data)

{

    NODE *temp;

    if (node == NULL)

    {

        printf("\nElement not found");
    }

    else if (data < node->data)

    {

        node->left = del(node->left, data);
    }

    else if (data > node->data)

    {

        node->right = del(node->right, data);
    }

    else

    { /* Now We can delete this node and replace with either minimum element in the right sub tree or maximum element in the left subtree */

        if (node->right && node->left)

        { /* Here we will replace with minimum element in the right sub tree */

            temp = findMin(node->right);

            node->data = temp->data;

            /* As we replaced it with some other node, we have to delete that node */

            node->right = del(node->right, temp->data);
        }

        else

        {

            /* If there is only one or zero children then we can directly remove it from the tree and connect its parent to its child */

            temp = node;

            if (node->left == NULL)

                node = node->right;

            else if (node->right == NULL)

                node = node->left;

            free(temp); /* temp is longer required */
        }
    }

    return node;
}

unsigned int getLeafCount(NODE *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left) +
               getLeafCount(node->right);
}

int countNonleaf(NODE *root)
{

    if (root == NULL || (root->left == NULL &&
                         root->right == NULL))
        return 0;

    return 1 + countNonleaf(root->left) +
           countNonleaf(root->right);
}

int maxDepth(NODE *node)
{
    if (node == NULL)
        return -1;
    else
    {

        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
void sumOfNodesAtNthLevel(NODE *root,
                          int k)
{
    if (root == nullptr)
        printf(" ");

    queue<NODE *> que;

    que.push(root);

    int level = 0;

    int sum = 0;

    int flag = 0;

    while (!que.empty())
    {

        int size = que.size();

        while (size--)
        {
            NODE *ptr = que.front();
            que.pop();

            if (level == k)
            {

                flag = 1;

                cout << ptr->data << " ";
            }
            else
            {

                if (ptr->left)
                    que.push(ptr->left);

                if (ptr->right)
                    que.push(ptr->right);
            }
        }

        level++;

        if (flag == 1)
            break;
    }
}
int addBT(NODE *root)
{
    if (root == NULL)
        return 0;
    return (root->data + addBT(root->left) + addBT(root->right));
}
int size(NODE *node)
{
    if (node == NULL)
        return 0;
    else
        return (size(node->left) + 1 + size(node->right));
}
int maxValue(NODE *node)
{
    if (node->right == NULL)
        return node->data;
    return maxValue(node->right);
}
int minValue(NODE *node)
{
    if (node->left == NULL)
        return node->data;
    return minValue(node->left);
}
int main()

{

    int data, ch, i, n;

    NODE *root = NULL;

    while (1)

    {

        printf("\n1.Insertion in Binary Search Tree");

        printf("\n2.Search Element in Binary Search Tree");

        printf("\n3.Delete Element in Binary Search Tree");

        printf("\n4.Inorder\n5.Preorder\n6.Postorder\n7.To count the number of leaf node\n8.To count the number of non leaf nodes in a tree");
        printf("\n9:To count the sum of all the nodes in a tree\n10:TO find the height of the tree");
        printf("\n11:Print all  of nodes at nth level of tree\n12 To find the number of nodes in a tree\n13:Find max\n14:Find min\n15:Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:
            printf("\nEnter N value: ");

            scanf("%d", &n);

            printf("\nEnter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2)\n");

            for (i = 0; i < n; i++)

            {

                scanf("%d", &data);

                root = createtree(root, data);
            }

            break;

        case 2:
            printf("\nEnter the element to search: ");

            scanf("%d", &data);

            root = search(root, data);

            break;

        case 3:
            printf("\nEnter the element to delete: ");

            scanf("%d", &data);

            root = del(root, data);

            break;

        case 4:
            printf("\nInorder Traversal: \n");

            inorder(root);

            break;

        case 5:
            printf("\nPreorder Traversal: \n");

            preorder(root);

            break;

        case 6:
            printf("\nPostorder Traversal: \n");

            postorder(root);

            break;

        case 7:
            printf("Leaf count of the tree is %d", getLeafCount(root)); 

            break;

        case 8:
            cout << countNonleaf(root);

            break;

        case 9:
            cout << "Sum of all the elements is: " << addBT(root) << endl;

            break;

        case 10:
            printf("Height of tree is %d", maxDepth(root));

            break;

        case 11:
            int level;
            printf("enter the level");
            scanf("%d", &level);

            sumOfNodesAtNthLevel(root, level);

            break;
        case 12:
            printf("Size of the tree is %d", (size(root) + 1)); 

            break;
        case 13:
            cout << maxValue(root);

            break;
        case 14:
            cout << minValue(root);

            break;
        case 15:
            exit(0);

            break;
        default:
            printf("\nWrong option");

            break;
        }
    }
    return 0;
}