#include <iostream>

template<class T, int ARRAYSIZE>
class List {
    private:
        int last;
    public:
    void selecSort();
    void swapData();
    void shellSort();
    void shellSort(int(const T&, const T&));
    void mergeSort(const int&, const int&);
    void mergeSort(const int&, const int&, cmp(const T&, const T&));

    bool isSorted();
};


template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::selecSort(){
int i(0), j, m;
     while(i < this->last){
        m = i;
        j = i + 1;

        while(j <= this->last){
            if(his->data[j] < this->data[m]){
                m = j;
            }
            j++;
        }
        if(m != 1){
            this->swapData(this->data[i], this->data[m]);
        }
        i++;
     }
}

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::shellSort(){
float fact(1.0/2.0);
int dif((this->last + 1) * fact), i, j;

while(dif > 0){
    i = dif;
    while(i <= this->last){
        i = dif;
        while(j >= dif and this->data[j - dif] > this->data[j]){
        this->swapData(this->data[j - dif], this->data[j]);
        j -= dif;
    }
    i++;
    }
    dif = series[++seq];
}
}


template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::shellSort(int cmp(const T&, const T&)){
int series = {510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701, 301, 132, 57,23, 10, 4, 1}
float fact(1.0/2.0);
int seq(0), dif(serie[seq]), i, j;
//int dif((this->last + 1) * fact), i, j;

while(dif > 0){
    i = dif;
    while(i <= this->last){

        while(j >= dif and cmp(this->data[j - dif], this->data[j])>0){
            this->swapData(this->data[j - dif], this->data[j]);
            j -= dif;
        }
        i++;
    }
    dif = series[++seq];
}
}


template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::mergeSort(int cmp(const T&, const T&)){
    this->sortDatamMerge(0, this-last, int cmp(const T&, const T&));
}

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::mergeSort(){
    this->sortDatamMerge(0, this-last);
}

//privado
template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::mergeSort(const int& leftEdge,const int& rightEdge){
    if(leftEdge >= rightEdge){ //criterio de paro
        return;
    }

    //Divide and conquer
    int m((leftEdge + rightEdge)/2);
    this->mergeSort(leftEdge, m);
    this->mergeSort(m + 1, rightEdge);

    //Intercalacion

    T temp[ARRAYSIZE];

    for(int i(leftEdge); i <= rightEdge; i++){
        temp[i] = this->data[i];
    }

    int i(leftEdge), j(m + 1), x(leftEdge);

    while(i <= m && j <= rightEdge){
        while(i<= m && temp[i] <= temp[j]){
            this->data[x++] = temp[i++];
            //i++;
            //x++;
        }
        if(i <= m){
            while(j <= rightEdge && temp[j] <= temp[i]){
                this>data[x++] = temp[j++];
            }
        }
    }
    while(i<= m && temp[i] <= temp[j]){
        this->data[x++] = temp[i++];
        //i++;
        //x++;
    }
    while(i<= m && temp[i] <= temp[j]){
        this->data[x++] = temp[j++];
        //i++;
        //x++;
    }
}

template<class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isSorted(){
    int i(0);

    while( i<= this->last){
        if(this->data[i] > this->data[i+1]);

        i++;
    }
}

//publico
template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::quickSort(){
    this->quisort(0, this->last);
}

template<class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::quickSort(const int& leftEdge, const int& rightEdge){
    if(leftEdge >= rightEdge){
        return;
    }

    //Separacion

    int i(leftEdge), j(rightEdge);

    while(i<j){

    
    while(i < j and this->data[i] <= this->data[rightEdge]){
        i++;
    }

        while(i < j &&& this->data[j] >= this->data[righEdge]){
            j--;
        }

        if(i != j){
            swapData(this->ata[i], this->data{j});
        }

    }

    if(i != rightEdge){
        this->swapData(this->data[i], this->data[rightEdge]);
    }

    // Divide and conquer

    this->sortDataQuick(leftEdge, i-1);
    this->sortDataQuick(i-1, rightEdge);

    
}