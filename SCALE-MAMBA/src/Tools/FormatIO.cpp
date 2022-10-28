/**
 * Copyright Tecnalia Research && Innovation
 * All Rights Reserved.
 */

#include "FormatIO.h"

FormatIO *FormatIO::singleton= NULL;

FormatIO::FormatIO(uint index, uint count)
{
  if (index >= count)
    {
      throw BadPlayerIndexException();
    }
  playerIndex= index;
  playerCount= count;
  playerFormatList= new PlayerFormat[playerCount];
}

FormatIO::~FormatIO()
{
  delete playerFormatList;
}

FormatIO *FormatIO::GetInstance(uint index, uint count)
{
  if (singleton == NULL)
    {
      singleton= new FormatIO(index, count);
    }
  return singleton;
}

FormatIO *FormatIO::GetInstance()
{
  if (singleton == NULL)
    {
      singleton= new FormatIO(0, 3);
    }
  return singleton;
}

Format *FormatIO::getFormatInput(uint *const player)
{
  uint index= playerIndex;
  if (player != NULL)
    {
      index= *player;
    }
  if (index >= playerCount)
    {
      throw BadPlayerIndexException();
    }
  return playerFormatList[index].getFormatInput();
}

Format *FormatIO::getFormatOutput(uint *const player)
{
  uint index= playerIndex;
  if (player != NULL)
    {
      index= *player;
    }
  if (index >= playerCount)
    {
      throw BadPlayerIndexException();
    }
  return playerFormatList[index].getFormatOutput();
}

// INPUT

FormatType FormatIO::getInputType(uint *const player)
{
  return getFormatInput(player)->getType();
}

bool FormatIO::setInputRaw(uint *const player)
{
  if (player == NULL) {
    for(uint i = 0; i < playerCount; i++)
    {
      getFormatInput(&i)->setRaw();
    }
    return true;
  }
  getFormatInput(player)->setRaw();
  return playerIndex == *player;
}

bool FormatIO::setInputCsvNColumns(uint nColumns, uint *const player)
{
  if (player == NULL) {
    for(uint i = 0; i < playerCount; i++)
    {
      getFormatInput(&i)->setCsvNColumns(nColumns);
    }
    return true;
  }
  getFormatInput(player)->setCsvNColumns(nColumns);
  return playerIndex == *player;
}

uint FormatIO::getInputCsvNColumns(uint *const player)
{
  return getFormatInput(player)->getCsvNColumns();
}

bool FormatIO::setInputJsonKey(string key, uint *const player)
{
  if (player == NULL) {
    for(uint i = 0; i < playerCount; i++)
    {
      getFormatInput(&i)->setJsonKey(key);
    }
    return true;
  }
  getFormatInput(player)->setJsonKey(key);
  return playerIndex == *player;
}

bool FormatIO::addInputJsonKey(string key, uint *const player)
{
  if (player == NULL) {
    for(uint i = 0; i < playerCount; i++)
    {
      getFormatInput(&i)->addJsonKey(key);
    }
    return true;
  }
  getFormatInput(player)->addJsonKey(key);
  return playerIndex == *player;
}

int FormatIO::getInputJsonKeyCount(uint *const player)
{
  return getFormatInput(player)->getJsonKeyCount();
}

string FormatIO::getInputJsonKey(uint *const player)
{
  return getFormatInput(player)->getJsonKey();
}

string FormatIO::getInputJsonKey(int index, uint *const player)
{
  return getFormatInput(player)->getJsonKey(index);
}

// OUTPUT

FormatType FormatIO::getOutputType(uint *const player)
{
  return getFormatOutput(player)->getType();
}

bool FormatIO::setOutputRaw(uint *const player)
{
  if (player == NULL) {
    for(uint i = 0; i < playerCount; i++)
    {
      getFormatOutput(&i)->setRaw();
    }
    return true;
  }
  getFormatOutput(player)->setRaw();
  return playerIndex == *player;
}

bool FormatIO::setOutputCsvNColumns(uint nColumns, uint *const player)
{
  if (player == NULL) {
    for(uint i = 0; i < playerCount; i++)
    {
      getFormatOutput(&i)->setCsvNColumns(nColumns);
    }
    return true;
  }
  getFormatOutput(player)->setCsvNColumns(nColumns);
  return playerIndex == *player;
}

uint FormatIO::getOutputCsvNColumns(uint *const player)
{
  return getFormatOutput(player)->getCsvNColumns();
}

bool FormatIO::setOutputJsonKey(string key, uint *const player)
{
  if (player == NULL) {
    for(uint i = 0; i < playerCount; i++)
    {
      getFormatOutput(&i)->setJsonKey(key);
    }
    return true;
  }
  getFormatOutput(player)->setJsonKey(key);
  return playerIndex == *player;
}

bool FormatIO::addOutputJsonKey(string key, uint *const player)
{
  if (player == NULL) {
    for(uint i = 0; i < playerCount; i++)
    {
      getFormatOutput(&i)->addJsonKey(key);
    }
    return true;
  }
  getFormatOutput(player)->addJsonKey(key);
  return playerIndex == *player;
}

int FormatIO::getOutputJsonKeyCount(uint *const player)
{
  return getFormatOutput(player)->getJsonKeyCount();
}

string FormatIO::getOutputJsonKey(uint *const player)
{
  return getFormatOutput(player)->getJsonKey();
}

string FormatIO::getOutputJsonKey(int index, uint *const player)
{
  return getFormatOutput(player)->getJsonKey(index);
}
