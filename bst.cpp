/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
#include <stdlib.h>
#include "general.h"
struct Node{
  int element;
  Bst right;
  Bst left;
};

Bst new_bst(){
  return 0;
}

void delete_bst(Bst bst){
  if(bst == 0) { return; }
  if(bst->left != 0) { delete_bst(bst->left); }
  if(bst->right != 0) { delete_bst(bst->right); }
sfree(bst);
}

int get_depth(Bst bst){
  if (bst == 0) {
    return 0;
  }
  int counter = 0;
  if (bst->right != 0) {
    counter = get_depth(bst->right);
  }
  if (bst->left != 0) {
    counter = get_depth(bst->left);
  }
  return counter;
}

void add(Bst* bst, int value){
  if(*bst == 0)
  {
    Bst new_bst = (Bst)malloc(sizeof(Node));
    new_bst->left = 0;
    new_bst->right = 0;
    new_bst->element = value;
    *bst = new_bst;
  }
  else if(value <= (*bst)->element)
  {
    add(&(*bst)->left, value);
  }
  else
  {
    add(&(*bst)->right, value);
  }
}

int root_value(Bst bst){
  if(bst != 0)
  {
    return bst->element;
  }
  else
  {
    return 0;
  }
}

Bst left_subtree(Bst root){
  if(root != 0)
  {
    return root->left;
  }
  else
  {
    return 0;
  }
}

Bst right_subtree(Bst root){
  if(root != 0)
  {
    return root->right;
  }
  else
  {
    return 0;
  }
}

int traverse_pre_order(Bst bst, int *elements, int start){
  if(bst == 0) { return 0; }
  elements[start] = bst->element;
  if(bst->left == 0 && bst->right == 0) { return 1; }
  int count = 0;
  count = traverse_pre_order(bst->left, elements, start + count +1);
  return count + traverse_pre_order(bst->right, elements, start + count +1) + 1;
}

int traverse_in_order(Bst bst, int *elements, int start){
  if(bst == 0) { return 0; }
  int count = 0;
  count = traverse_in_order(bst->left, elements, start);
  elements[count + start] = bst->element;
  count += traverse_in_order(bst->right, elements, count + start +1);
  return count+1;
}

int traverse_post_order(Bst bst, int *elements, int start){
  if(bst == 0) { return 0; }
  int count = 0;
  count = traverse_post_order(bst->left, elements, start);
  count += traverse_post_order(bst->right, elements, count + start);
  elements[count + start] = bst->element;
  return count+1;
}

bool are_equal(Bst bst1, Bst bst2){
  if(bst1 == 0 && bst2 == 0) { return true; }
  if(bst1 == 0 || bst2 == 0) { return false; }
  return are_equal(bst1->left, bst2->left) && are_equal(bst1->right,bst2->right) && (bst1->element == bst2->element);
}

void most_left_longest_branch(Bst bst, Bst* branch){
  if(bst == 0) { return; }
  int depth_left = get_depth(bst->left);
  int depth_right = get_depth(bst->right);

  add(branch, bst->element);
  if(depth_left >= depth_right)
  {
    most_left_longest_branch(bst->left, branch);
  }
  else
  {
    most_left_longest_branch(bst->right, branch);
  }
}

int get_number_of_subtrees(Bst bst){
  if(bst == 0) { return -1; }
  int count = get_number_of_subtrees(bst->left) + 1;
  return count + get_number_of_subtrees(bst->right) + 1;
}
