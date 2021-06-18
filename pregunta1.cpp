 /**
 * Implemente un algoritmo que permita eliminar los nodos que formen parte de una sublista
 * en una lista doblemente enlazada. Validar todos los casos posibles. 
 *
 * Ejemplo 1:
 * List:   		null <- 10 <-> 5 <-> 3 <-> 2 <-> 23 <-> 5 -> null
 * SubList:   	null <- 3 <-> 2 <-> 23 -> null
 * Output:  	null <- 10 <-> 5 <-> 5 -> null 
 *
 * Ejemplo 2:
 * List:   		null <- 3 <-> 2 <-> 23 -> null
 * SubList:   	null <- 3 <-> 2 <-> 23 -> null
 * Output:  	null 
 *
 * Ejemplo 3:
 * List:   		null <- 10 <-> 5 <-> 3 <-> 2 <-> 23 <-> 5 -> null
 * SubList:   	null <- 3 <-> 2 <-> 25 -> null
 * Output:  	null <- 10 <-> 5 <-> 3 <-> 2 <-> 23 <-> 5 -> null 
 **/

#include <iostream>
#include "tester.h" 

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void PushFront(Node* &list, int value){
  Node* newNode = new Node();
  newNode->data =value;
  newNode->next = nullptr;
  newNode->prev = nullptr;

  if (list == nullptr) list = newNode;

  else{
    list->prev = newNode;
    list->prev->next=list;
    list = newNode;
  }
}

void remove (Node* &list, Node* sublist, Node* aux){
  Node* head = list;

  while (list!=aux){
    list = list->next;
  }

  Node* aux_list2 = list;
  Node* aux2 = sublist;
  while(aux2!=nullptr){
    aux_list2=aux_list2->next;
    aux2=aux2->next;
  }

  list->prev->next = aux_list2;
  list = head;

}


void RemoveSublist(Node* &list, Node* sublist)
{
  if (list == nullptr or sublist==nullptr) return;

  Node* aux = list;
  Node* aux2 = sublist;
  Node* aux3 = nullptr;


  while (aux!=nullptr){
    aux3 = aux;
    while (aux2!=nullptr){
      if (aux->data == aux2->data){
        aux=aux->next;
        aux2 = aux2->next;
      }
      else break;
    }

    if(aux2 == nullptr){

      remove (list,sublist, aux3);
      break;
    }
    aux2 = sublist;
    aux = aux->next;
  }

}

//********************************* MAIN ********************************************//
void test1(){
    Node* lista = nullptr;
    PushFront(lista, 5);
    PushFront(lista, 23);
    PushFront(lista, 2);
    PushFront(lista, 3);
    PushFront(lista, 5);
    PushFront(lista, 10);

    Node* sublista = nullptr;
    PushFront(sublista, 23);
    PushFront(sublista, 2);
    PushFront(sublista, 3);
    
    RemoveSublist(lista, sublista);

    ASSERT(lista->data == 10, "The function RemoveSublist is not working");    
    ASSERT(lista->next->next->data == 5, "The function RemoveSublist is not working");
}

void test2(){
    Node* lista = nullptr;
    PushFront(lista, 5);
    PushFront(lista, 23);
    PushFront(lista, 2);
    PushFront(lista, 3);
    PushFront(lista, 5);
    PushFront(lista, 10);

    Node* sublista = nullptr;
    PushFront(sublista, 25);
    PushFront(sublista, 2);
    PushFront(sublista, 3);
    
    RemoveSublist(lista, sublista);

    ASSERT(lista->data == 10, "The function RemoveSublist is not working");    
    ASSERT(lista->next->next->data == 3, "The function RemoveSublist is not working");
}

int main(){
    test1();
    test2();
    //Success 4/4
    return 0;


    //Ejercicio 1 completo:
    //Success 1/1
    //Success 2/2
    //Success 3/3
    //Success 4/4
}