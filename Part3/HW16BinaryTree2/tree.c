// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

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


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
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
bool helper(TreeNode * root,int val)
{
 if(root==NULL)
 {
   return false;
 } 
 if(root->value == val)
 {
   printf("%d\n",root->value);
   return true;
 }
 else if(helper(root->left,val) == true)
 {
   printf("%d\n",root->value);
   return true;
 }
 else if(helper(root->right,val) == true)
 {
   printf("%d\n",root->value);
   return true;
 }
 return false;
}

#ifdef TEST_PRINTPATH
void printPath(Tree * tr, int val)
{
  if(helper(tr->root,val))
  {
    return;
  }
}
#endif
