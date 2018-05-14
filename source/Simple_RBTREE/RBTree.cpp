#include "RBTree.h"


//Implementações da classe RBTree
RBTree::RBTree(){
    nil = NULL;
    root = NULL;
	numberOfNodes = 0;
}

RBTree::~RBTree(){
	numberOfNodes = 0;
	deleteTree(root);
	delete nil;
}

void RBTree::print(){
    print(root);
}

int RBTree::size() const{
    return numberOfNodes;
}

bool RBTree::isEmpty() const{
    return numberOfNodes == 0;
}

void RBTree::insertFixUp(Node*& node){

    if(root == node){
        root->color = BLACK;
        return;
    }

            //Verifica as propriedades Arvore Rubro Negra
    while (node!= root && node->parent->color == RED){
                //Se tiver violação
        if(node->parent == node->parent->parent->left){
            Node* Y = node->parent->parent->right;
            if(Y != NULL && Y->color == RED){//Case 1: Tio é vermelho
                 
                node->parent->color = BLACK;
                Y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;

            }else{ //Case 2: Tio é preto
                  
                if(node == node->parent->right){
                    node = node->parent;
                    leftRotation(node);
                    printf(" Rotacao Esquerda \n");
                }

                //Case 3: recolore e rotaciona
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotation(node);
                printf(" Rotacao Direita \n");
            }
 
        }else{
     
            Node* X = NULL;
 			X = node->parent->parent->left;
            if(X != NULL && X->color == BLACK){//Case 1
                node->parent->color = RED;
                X->color = RED;
                node->parent->parent->color = BLACK;
                node = node->parent->parent;

            }else{// Case 2
                if(node == node->parent->left){
                    node = node->parent;
                    rightRotation(node);
                    printf(" Rotacao Direita \n");
                }
                //Case 3: recolore e rotaciona
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotation(node->parent->parent);
                printf(" Rotacao Esquerda \n");
 
            }
 
        }
        root->color = BLACK; //recolorir a raiz como preta conforme necessário
    } 
}


void RBTree::insert(int value){

    Node* parent, *q;
    Node* tmp = new Node(value); /* instanciando novo no a ser adicionado */
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->color = RED;
    parent = root; /* pai desse no recebe a raiz */
    q = NULL; /* aux para armazenar valor do pai */

    if(root == NULL){ /* se a raiz for nula entao ela recebe o novo no e muda cor raiz para preto */
        root = tmp;
        tmp->parent = NULL;
    }else{ /* se nao verificar onde colocar o no */

        while(parent != NULL){ /* enquanto o pai ( que recebeu a raiz) for nulo continuar procurando quem sera o pai do no */
            q = parent;
            if(parent->value < tmp->value){
                parent = parent->right;

            }else{
                parent = parent->left; /* no fianl (q) estara com o valor do pai do nó */
            }
        }

        tmp->parent = q; /* apos achar o seu pai guardamos a referencia dele no atributo parent*/
        if(q->value < tmp->value){ /* entao realizamos aquela velha inserção de se chave for maior q valor do pai add direita se nao esquerda */
            q->right = tmp;

        }else{
            q->left = tmp;
        }
    }
    printf(" Adicionou [%d] \n", tmp->value);
    insertFixUp(tmp);
}



void RBTree::RBTransplant(Node* u, Node* v){

    if(u->parent == nil){
        root = v;
    }else if(u == u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    v->parent = u->parent;
}

bool RBTree::remove(int value){    
    Node* z = root;
    Node* x;
    Node* y;

    //Busca pelo elemento
    while(z != nil && z->value != value){
       if (value < z->value){
           z = z->left;

       }else{
           z = z->right;
       }
    }
    
    //Se não encontrou o elemento
    if (z == nil){
        return false;
    }
    
    //Z aponta para o elemento a ser removido
    y = z;
    int originalColor = y->color;
    
    if (z->left == nil){
        x = z->right;
        
        //Faz o filho direito assumir o lugar de z
        RBTransplant(z, z->right);

    }else{

        if (z->right == nil){
            x = z->left;
            RBTransplant(z, z->left);
        }else{
            y = sucessor(z);
            originalColor = y->color;
            x = y->right;
            
            if (y->parent == z){
                x->parent = y;

            }else{
                RBTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            
            RBTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
    }
    
    if (originalColor == BLACK){
        removeFixUp(x);
    }

    delete z;
    
    return true;
}

void RBTree::removeFixUp(Node*& x){
    Node* w;
    
    while (x != root && x->color == BLACK) {
        //Se x for filho esquerdo
        if (x == x->parent->left){
            w = x->parent->right;
            
            if (w->color == RED){ //Caso 1
            
                w->color = BLACK;
                x->parent->color = RED;
                leftRotation(x->parent);
                w = x->parent->right;
            }
            
            if (w->left->color == BLACK && w->right->color == BLACK){ //Caso 2
            
                w->color = RED;
                x = x->parent;

            }else{
                if (w->right->color == BLACK){ //Caso 3
                
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotation(w);
                    w = x->parent->right;
                }
                
                //Caso 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotation(x->parent);
                
                x = root;
            }
        }else{ //x é filho direito
        
            w = x->parent->left;
            
            if (w->color == RED){ //Caso 1
            
                w->color = BLACK;
                x->parent->color = RED;
                leftRotation(x->parent);
                w = x->parent->left;
            }
            
            if (w->right->color == BLACK && w->left->color == BLACK){ //Caso 2
            
                w->color = RED;
                x = x->parent;

            }else{
                if (w->left->color == BLACK){ //Caso 3
                
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotation(w);
                    w = x->parent->left;
                }
                
                //Caso 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotation(x->parent);
                
                x = root;
            }
        }
    }
    x->color = BLACK;
}

Node* RBTree::sucessor(Node* node){
    Node* suc = node->right;
    
    while (suc->left != nil){
        suc = suc->left;
    }
    
    return suc;
}

bool RBTree::contains(int value){
	Node* x = root;

	while(x != nil){
		if(x->value == value){
			return true;
		}

		//x = value < x->value ? x->left : x->right;
       if (value < x->value){
           x = x->left;
       }else{
           x = x->right;
       }
	}

	return false;
}

void RBTree::leftRotation(Node* node){
	Node* y = node->right;
	node->right = y->left;

	if(y->left != nil){
		y->left->parent = node;
	}

	y->parent = node->parent;
	if(node->parent == nil){
		root = y;

	}else{
		if(node == node->parent->left){
			node->parent->left = y;
		}else{
			node->parent->right = y;
		}
	}

	y->left = node;
	node->parent = y;
}

void RBTree::rightRotation(Node* node) {
	Node* y = node->left;
	node->left = y->right;

	if(y->right != nil){
		y->right->parent = node;
	}

	y->parent = node->parent;
	if(node->parent == nil){
		root = y;

	}else{
		if(node == node->parent->right){
			node->parent->right = y;
		}else{
			node->parent->left = y;
		}
	}

	y->right = node;
	node->parent = y;
}

void RBTree::deleteTree(Node* node){
	if(node != nil){
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

void RBTree::print(Node* node){
	static int offset = 0;

	for (int i = 0; i < offset; ++i){
		printf(" ");
	}

	if (node == nil) {
		printf("-[B]\n");
		return;
	}
	
	if(node->color == BLACK){
		printf("%d[B]\n", node->value);

	}else{
		printf("%d[R]\n", node->value);
	}

	offset += 3;
	print(node->left);
	print(node->right);
	offset -= 3;
}
