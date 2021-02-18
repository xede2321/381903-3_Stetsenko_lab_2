#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000;


template <class ValType>
class TVector
{
protected:
  ValType* pVector;
  int Size;
  int StartIndex;
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector& v);               
  virtual ~TVector();

  int GetSize() { return Size; }
  int GetStartIndex() { return StartIndex; } 
  ValType& operator[](int pos);            
  bool operator==(const TVector& v) const;  
  TVector& operator=(const TVector& v);    

 
  TVector  operator+(const ValType& val);
  TVector  operator-(const ValType& val); 
  TVector  operator*(const ValType& val);  
  TVector  operator/(const ValType& val);  

  
  TVector  operator+(const TVector& v);    
  TVector  operator-(const TVector& v);   
  TVector  operator*(const TVector& v);  


  friend istream& operator>>(istream& in, TVector& v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream& out, const TVector& v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
  if (s < 0 || s > MAX_VECTOR_SIZE || si < 0)
  {
    throw "Error";
  }
  pVector = new ValType[s];
  Size = s;
  StartIndex = si;
}

template <class ValType> 
TVector<ValType>::TVector(const TVector<ValType>& v)
{
  pVector = new ValType[v.Size];
  Size = v.Size;
  StartIndex = v.StartIndex;

  for (int i = 0; i < Size; i++)
  {
    pVector[i] = v.pVector[i];
  }
}

template <class ValType>
TVector<ValType>::~TVector()
{
  if (pVector != 0)
  {
    delete[] pVector;
  }
  pVector = 0;
  Size = 0;
  StartIndex = 0;
}

template <class ValType>
ValType& TVector<ValType>::operator[](int index)
{
  if (index < 0 || index > Size)
  {
    throw "Error";
  }
  return pVector[index - StartIndex];
}

template <class ValType>
bool TVector<ValType>::operator==(const TVector& v) const
{
  bool res = true;
  if (Size != v.Size)
  {
    res = false;
  }

  for (int i = 0; i < Size; i++)
  {
    if (pVector[i] != v.pVector[i])
    {
      res = false;
    }
  }
  return res;
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
  if (this == &v)
  {
    return *this;
  }

  if (Size != v.Size)
  {
    if (pVector != NULL)
    {
      delete[] pVector;
    }
    pVector = new ValType[v.Size];
  }

  Size = v.Size;
  StartIndex = v.StartIndex;
  for (int i = 0; i < Size; i++)
  {
    pVector[i] = v.pVector[i];
  }
  return *this;
}

template <class ValType> 
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
  TVector<ValType> res;
  res.Size = Size;
  res.pVector = new ValType[res.Size];

  for (int i = 0; i < res.Size; i++)
  {
    res.pVector[i] = pVector[i] + val;
  }
  return res;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
  TVector<ValType> res;
  res.Size = Size;
  res.pVector = new ValType[res.Size];

  for (int i = 0; i < res.Size; i++)
  {
    res.pVector[i] = pVector[i] - val;
  }
  return res;
}

template <class ValType> 
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
  TVector<ValType> res;
  res.Size = Size;
  res.pVector = new ValType[res.Size];

  for (int i = 0; i < res.Size; i++)
  {
    res.pVector[i] = pVector[i] * val;
  }
  return res;
}

template<class ValType>
inline TVector<ValType> TVector<ValType>::operator/(const ValType& val)
{
  TVector<ValType> res;
  res.Size = Size;
  res.pVector = new ValType[res.Size];

  for (int i = 0; i < res.Size; i++)
  {
    res.pVector[i] = pVector[i] / val;
  }
  return res;
}

template <class ValType> 
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
  if (v.Size != Size)
  {
    throw "Error";
  }
  TVector<ValType> res;
  res.Size = Size;
  res.pVector = new ValType[res.Size];
  for (int i = 0; i < res.Size; i++)
  {
    res.pVector[i] = pVector[i] + v.pVector[i];
  }
  return res;
}

template <class ValType> 
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
  if (v.Size != Size)
  {
    throw "Error";
  }
  TVector<ValType> res;
  res.Size = Size;
  res.pVector = new ValType[res.Size];
  for (int i = 0; i < res.Size; i++)
  {
    res.pVector[i] = pVector[i] - v.pVector[i];
  }
  return res;
}

template <class ValType> 
TVector<ValType> TVector<ValType> ::operator*(const TVector<ValType>& v)
{
  if (v.Size != Size)
  {
    throw "Error";
  }
  TVector<ValType> res;
  res.Size = Size;
  res.pVector = new ValType[res.Size];
  for (int i = 0; i < res.Size; i++)
  {
    res.pVector[i] = pVector[i] * v.pVector[i];
  }
  return res;
}
#endif 