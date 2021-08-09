#pragma once
#include "Hashing.h"

HashMap::HashMap() {
    //! replaces self
    //! ensures self ={ } and
    //! That all Sequences in self are intialzied 
    
    table = new Sequence<HashEntry>*[TABLE_SIZE];
  
    for (int i = 0; i < TABLE_SIZE; i++)
    { 
        Sequence<HashEntry>* y = new Sequence<HashEntry>(); //have to delete the extras maybe not 
        table[i] = y;
    }//for
    
}//HashMap
HashMap::~HashMap() {
   // for (int i = 0; i < TABLE_SIZE; i++)
     //   if (table[i] != NULL)
       //     delete table[i];
       // delete[] table;
    
}

 bool HashMap ::inMap(string key)
{    //! restores key  
     //! ensures: inMap = (key is or is not in Domain(self)
     
      Sequence<HashEntry>* hashEntrySequence = table[hash(key)];
        bool b = false;
         string mapKey;

         for (int i = 0; i < hashEntrySequence->length(); i++)
         {
            mapKey = hashEntrySequence->entry(i).getKey();
            if (mapKey == key) {
                b = true;
               return b;
            }//if      
     }//for
  
         return b;
    
}//inMap

 void HashMap::put(string key, AirportRecord value)
 {  
     //! updates self
     //! restores key and value
     //! ensures: self = #self union {#key, #value}
   
     int index = hash(key);
     HashEntry new_hashEntry = HashEntry(key, value);
     Sequence<HashEntry> * hashEntrySequence = table[index];


     hashEntrySequence->addLast(new_hashEntry, hashEntrySequence->length());

    
    
 }//put

 int HashMap::size()
 {
    //! restores self
    //! ensures: length = |self| / unintialized self 
    
     int total = 0;
     for (int i = 0; i < TABLE_SIZE; i++) {
         Sequence<HashEntry>* hashEntrySequence = table[i];
         if (hashEntrySequence != NULL)
         {
             total += table[i]->length();
             //cout << "\nTable at index \n" << i << ": " << hashEntrySequence->length();
         }
     }
     return total;
 }

 void HashMap::remove(string key)
 {
     //! restores key
     //! requires #key= Domain(self) 
     //! ensures: self = #self /{(#key,value)}


     Sequence<HashEntry>* hashEntrySequence = table[hash(key)];
          
     for ( int i=0 ; i < hashEntrySequence->length(); i++)
     {  
         
     if (hashEntrySequence->entry(i).getKey() == key)
        {
         
         hashEntrySequence->remove(hashEntrySequence->entry(i), i);
         
        }
     }  
 }

int HashMap::hash(string key) {
    //! restores key 
    //! ensures: hash = #key ASCII equivalent % |self|

   int stringtoInt = 0;
    for (int i = 0; i < key.length(); i++)
        {
            char x = key.at(i);
            stringtoInt += x;
        }
        return stringtoInt % TABLE_SIZE;
    }

void HashMap::swap(string key,AirportRecord& x)
{   //! restores key
    //! requires #key = Domain(self)
    //! ensures: self / {#key, x} and
    //! self = #self union {#x   key,#xvalue}

    remove(key);
    put(x.code, x);

}

void HashMap::outputMap() {
    //! restores self
    //! ensures: self = #self
    
    string outkey;
   
    cout << "\n{\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        
        for (int j = 0; j < table[i]->length(); j++) {

            if (table[i]->length() <= 0 || NULL) { i++; }

            else 
            { 
               outkey = table[i]->entry(j).getKey(); 
             AirportRecord outvalue = table[i]->entry(j).getValue();
             cout <<"("<<outkey<<","<<outvalue<<")\n";
            }
        }
    }
    cout << "}";
 }

