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
struct Node{
  int element;
  Bst right;
  Bst left;
};

Bst new_bst(){
  Bst newbst = (Bst)malloc(sizeof(Node));
  newbst->element = 0;
  newbst->right = 0;
  newbst->left = 0;
  return newbst;
}

void delete_bst(Bst bst){}

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

void add(Bst* bst, int value){}

int root_value(Bst bst){}

Bst left_subtree(Bst root){}

Bst right_subtree(Bst root){}

int traverse_pre_order(Bst bst, int *elements, int start){}

int traverse_in_order(Bst bst, int *elements, int start){}

int traverse_post_order(Bst bst, int *elements, int start){}

bool are_equal(Bst bst1, Bst bst2){}

void most_left_longest_branch(Bst bst, Bst* branch){}

int get_number_of_subtrees(Bst bst){}
