/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 18.04.2021
*/

#ifndef QDICTIONARY_H
#define QDICTIONARY_H

#include <QVector>
#include <QString>
#include <QDebug>

#include <iostream>
using namespace std;

//Implementation of a Custom Dictionary class
//Used here QVector
//Used here template specification of C++
template <typename TKey, typename TValue> class Dictionary {

private:
    TKey  key;
    TValue  value;
    unsigned int size =0;

    QVector<TKey> * arrKeys = new QVector<TKey>(1);
    QVector<TValue> * arrValues = new QVector<TValue>(1);

    QString controlKeyOutput(TKey k){
        std::string t = typeid(TKey).name();
        if(t == "int" ) return QString::number(k);
        //else if(t == "class QString" ) return k;
        else return "";
    }

    //I have no ideo why it is returning 7QString.
    //it was returning class QString at QT 5.8
    QString controlValueOutput(TValue v){
        std::string t = typeid(TValue).name();
        if(QString::fromStdString(t).indexOf("QString") > -1) return v;
        else return "";
    }


public:

    void add(TKey k, TValue v){
        arrKeys->append(k);
        arrValues->append(v);
        size++;

        //prepare for next adding
        arrKeys->resize(size+1);
        arrKeys->resize(size+1);
    }

    TValue getWithkey(TKey k){
        int index = arrKeys->indexOf(k);
        return arrValues->at(index);
    }


    void removeFromIndex(int i){
        arrKeys->remove(i);
        arrValues->remove(i);
        size--;

        //prepare for next adding
        arrKeys->resize(size-1);
        arrKeys->resize(size-1);
    }

    void removeFromKey(TKey k){
        int index = arrKeys->indexOf(k);
        removeFromIndex(index);
    }

    void removeFromValue(TValue v){
        int index = arrValues->indexOf(v);
        removeFromIndex(index);
    }

    int getSize(){ return size; }

    QString getPairAtKey(TKey k){

        qDebug() << "TValue türü : " << typeid(TValue).name() << Qt::endl;

        int index = arrKeys->indexOf(k);
        QString rK =  controlKeyOutput( arrKeys->at(index) ) ;
        QString rV =  controlValueOutput( arrValues->at(index) );
        return rK + "=" + rV;
    }

    QString getAllValues(){
        QString output = "";
        for(unsigned int i=0; i<arrValues->size(); i++){
            output += controlValueOutput(arrValues->at(i)) + "\n";
        }
        return output;
    }


};

#endif // QDICTIONARY_H
