// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
} 

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
TreeNode* createNode(int data)
{
  TreeNode * node = malloc(sizeof(TreeNode));
  node -> value = data;
  node->left = node->right = NULL;
  return node;
}
int searchbinary (int *arr, int start, int end, int value)
{
  int index = start;
  while (index <= end)
  {
    if (arr[index]==value)
    {
      break;
    }
    index ++;
  }
  return index;
}
TreeNode * binarytree(int * inArray, int * postArray, int startindex, int endindex, int*postIndex)
{
  if (startindex > endindex)
  {
    return NULL;
  }
  TreeNode * newnode = createNode(postArray[*postIndex]);
  (*postIndex) --;
  if (startindex == endindex)
  {
    return newnode; 
  }
  int initialIndex;
  initialIndex = searchbinary(inArray,startindex,endindex,newnode->value);
  newnode -> right = binarytree(inArray,postArray,initialIndex+1,endindex,postIndex);
  newnode -> left = binarytree(inArray,postArray,startindex,initialIndex -1,postIndex);
  return newnode;
}
Tree * buildTree(int * inArray, int * postArray, int size)
{
  int postIndex;
  postIndex = size - 1;
  Tree * root_of_tree = malloc(sizeof(Tree));
  root_of_tree->root = binarytree(inArray, postArray, 0, size - 1, &postIndex);
  return root_of_tree;
}
#endif
