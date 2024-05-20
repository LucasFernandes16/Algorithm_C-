#include <iostream>
#include <string>

using namespace std;
bool decision(int p, int p1, int c, int c1, int d, int d1){
  if (p > p1){
    return true;
  }else if(p == p1){
    if(c > c1){
      return true;
    }else if(c == c1){
      if(d < d1){
        return true;
      }else{
        return false;
      }
    }else{
      return false;
    }
  }
  else{
    return false;
  }
}

bool decision2(int p, int p1, int c, int c1, int d, int d1){
  if (p < p1){
    return true;
  }else if(p == p1){
    if(c < c1){
      return true;
    }else if(c == c1){
      if(d > d1){
        return true;
      }else{
        return false;
      }
    }else{
      return false;
    }
  }
  else{
    return false;
  }
}
struct Lista_Candidatos{
  char nome[30];
  int nota;
  int idade;
  int ordem;
};

int hoarePartition(Lista_Candidatos* arr, int l, int r){
    int p = (arr+ l )->nota;
    int p2 = (arr+l)->idade;
    int p3 = (arr+l)->ordem;
    int i = l;// in this case we dont have to do (l-1) because the first element is the pivot and we haven't to change
    int j = r + 1;// r+1 because in the first verification the j goes to the last element of the array
    do{
        do{
            i = i+1;
        }while(not(decision(p, (arr + i)->nota, p2, (arr+i)->idade, p3, (arr+i)->ordem) or i>=r));
        do{
            j = j - 1;
        }while(not(decision2(p, (arr+j)->nota, p2, (arr+j)->idade, p3, (arr+j)->ordem)));
        Lista_Candidatos temp = *(arr+i);
        *(arr+i) = *(arr+j);
        *(arr+j) = temp;
    }while(not(i >= j));
    Lista_Candidatos temp = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = temp;
    
    Lista_Candidatos temp2 = *(arr+l);
    *(arr+l) = *(arr+j);
    *(arr+j) = temp2;
    
    return j;
}


void quickSort(Lista_Candidatos *arr, int l, int r){
    if(l < r){    
        int s; // split position
        s = hoarePartition(arr, l, r);
        quickSort(arr, l, s-1);
        quickSort(arr, s+1, r);
    }
}

int main(){
  int cargos;
  cin >> cargos;
  int a = 1;
  for(int i = 0; i < cargos;i++){
    int qnt_inscritos,qnt_vagas;
    cin >> qnt_inscritos >> qnt_vagas;
    Lista_Candidatos *candidatos = new Lista_Candidatos[qnt_inscritos];

    for(int j = 0; j< qnt_inscritos;j++){
      Lista_Candidatos *novo_candidato = new Lista_Candidatos;
      cin >> novo_candidato->nome >> novo_candidato->nota >> novo_candidato->idade;
      novo_candidato->ordem = j+1;
      *(candidatos+j) = *novo_candidato;
      delete novo_candidato;

    }
    quickSort(candidatos, 0, qnt_inscritos-1);
    cout << "cargo " << a <<":" << endl;
    if(qnt_vagas > qnt_inscritos){
      for(int i = 0; i < qnt_inscritos; i++){
        cout << (candidatos + i)->nome<< endl; 
      }
      for(int j = 0; j < qnt_vagas - qnt_inscritos; j++){
        cout << "x"<< endl;
      }
    }else{
      for(int i = 0; i < qnt_vagas; i++){
        cout << (candidatos + i)->nome << endl;
    }
    }
    a++;
    delete[] candidatos;
  }

  return 0;
}