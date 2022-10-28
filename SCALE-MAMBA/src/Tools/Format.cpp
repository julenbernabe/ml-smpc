/**
 * Copyright Tecnalia Research && Innovation
 * All Rights Reserved.
 */

#include "Format.h"

Format::Format()
{
  formatType= FormatType::RAW;
  formatCsv= NULL;
  formatJson= NULL;
}

Format::~Format()
{
  if (formatCsv != NULL)
    {
      delete formatCsv;
    }
  if (formatJson != NULL)
    {
      delete formatJson;
    }
}

FormatType Format::getType()
{
  return formatType;
}

// RAW

void Format::setRaw()
{
  formatType= FormatType::RAW;
  clear();
}

// CSV

void Format::setCsvNColumns(uint nColumns)
{
  if (formatType == FormatType::CSV)
    {
      formatCsv->setNColumns(nColumns);
      return;
    }

  formatType= FormatType::CSV;
  formatCsv= new FormatCsv(nColumns);

  clear();
}

uint Format::getCsvNColumns()
{
  if (formatType != FormatType::CSV)
    {
      throw FormatException();
    }

  return formatCsv->getNColumns();
}

// JSON

void Format::setJsonKey(string key)
{
  // Retro-compatibility
  if (key.empty())
    {
      setRaw();
      return;
    }

  if (formatType == FormatType::JSON)
    {
      formatJson->setKey(key);
      return;
    }

  formatType= FormatType::JSON;
  formatJson= new FormatJson();
  formatJson->addKey(key);

  clear();
}

void Format::addJsonKey(string key)
{
  if (formatType == FormatType::JSON)
    {
      formatJson->addKey(key);
      return;
    }

  formatType= FormatType::JSON;
  formatJson= new FormatJson();
  formatJson->addKey(key);

  clear();
}

int Format::getJsonKeyCount()
{
  if (formatType != FormatType::JSON)
    {
      throw FormatException();
    }

  return formatJson->getKeyCount();
}

string Format::getJsonKey()
{
  return getJsonKey(0);
}

string Format::getJsonKey(int index)
{
  if (formatType != FormatType::JSON)
    {
      throw FormatException();
    }

  return formatJson->getKey(index);
}

void Format::clear()
{
  if (formatType != FormatType::CSV && formatCsv != NULL)
    {
      delete formatCsv;
      formatCsv= NULL;
    }
  if (formatType != FormatType::JSON && formatJson != NULL)
    {
      delete formatJson;
      formatJson= NULL;
    }
}
