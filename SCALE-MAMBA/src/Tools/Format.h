/**
 * Copyright Tecnalia Research && Innovation
 * All Rights Reserved.
 */

#ifndef _FORMAT_CLASS
#define _FORMAT_CLASS

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <exception>

enum class FormatType {
  RAW,
  CSV,
  JSON
};

struct FormatException : public exception
{
  const char *what() const throw()
  {
    return "Wrong format";
  }
};

class Format
{
protected:
  // CSV class
  class FormatCsv
  {
  private:
    uint nColumns;

  public:
    FormatCsv(uint nColumns)
    {
      setNColumns(nColumns);
    }

    void setNColumns(uint nColumns)
    {
      this->nColumns= nColumns;
    }

    uint getNColumns()
    {
      return nColumns;
    }
  };

  // JSON class
  class FormatJson
  {
  private:
    vector<string> keys = {};

  public:
    FormatJson()
    {
      keys = {};
    }

    ~FormatJson()
    {
    }

    void clear()
    {
      keys.clear();
    }

    void setKey(string key)
    {
      clear();
      addKey(key);
    }

    void addKey(string key)
    {
      keys.push_back(key);
    }

    int getKeyCount()
    {
      return keys.size();
    }

    string getKey(int index)
    {
      return keys[index];
    }
  };

  // Member variables
  FormatType formatType= FormatType::RAW;
  FormatCsv *formatCsv= NULL;
  FormatJson *formatJson= NULL;

public:
  Format();
  ~Format();

  FormatType getType();

  // Raw
  void setRaw();

  // CSV
  void setCsvNColumns(uint nColumns);
  uint getCsvNColumns();

  // JSON
  void setJsonKey(string key);
  void addJsonKey(string key);
  int getJsonKeyCount();
  string getJsonKey();
  string getJsonKey(int index);

protected:
  void clear();
};

#endif
