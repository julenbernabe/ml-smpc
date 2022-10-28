/**
 * Copyright Tecnalia Research && Innovation
 * All Rights Reserved.
 */

#ifndef _FORMAT_IO
#define _FORMAT_IO

#include "Format.h"
#include <string>

struct BadPlayerIndexException : public exception
{
  const char *what() const throw()
  {
    return "Bad player index";
  }
};

/**
 * @brief Singleton to manage input & output format configuration
 *
 */
class FormatIO
{
private:
  class PlayerFormat
  {
  private:
    Format *formatInput;
    Format *formatOutput;

  public:
    PlayerFormat()
    {
      formatInput= new Format();
      formatOutput= new Format();
    }

    ~PlayerFormat()
    {
      delete formatInput;
      delete formatOutput;
    }

    Format *getFormatInput()
    {
      return formatInput;
    }

    Format *getFormatOutput()
    {
      return formatOutput;
    }
  };

  uint playerIndex;
  uint playerCount;
  PlayerFormat *playerFormatList;

protected:
  FormatIO(uint index, uint count);

  static FormatIO *singleton;

  Format *getFormatInput(uint *const player= NULL);
  Format *getFormatOutput(uint *const player= NULL);

public:
  ~FormatIO();

  FormatIO(FormatIO &other)= delete;
  void operator=(const FormatIO &)= delete;

  static FormatIO *GetInstance(uint index, uint count);
  static FormatIO *GetInstance();

  // TODO: Destructor

  // INPUT
  FormatType getInputType(uint *const player= NULL);

  bool setInputRaw(uint *const player= NULL);

  bool setInputCsvNColumns(uint nColumns, uint *const player= NULL);
  uint getInputCsvNColumns(uint *const player= NULL);

  bool setInputJsonKey(string key, uint *const player= NULL);
  bool addInputJsonKey(string key, uint *const player= NULL);
  int getInputJsonKeyCount(uint *const player= NULL);
  string getInputJsonKey(uint *const player= NULL);
  string getInputJsonKey(int index, uint *const player= NULL);

  // OUTPUT
  FormatType getOutputType(uint *const player= NULL);

  bool setOutputRaw(uint *const player= NULL);

  bool setOutputCsvNColumns(uint nColumns, uint *const player= NULL);
  uint getOutputCsvNColumns(uint *const player= NULL);

  bool setOutputJsonKey(string key, uint *const player= NULL);
  bool addOutputJsonKey(string key, uint *const player= NULL);
  int getOutputJsonKeyCount(uint *const player= NULL);
  string getOutputJsonKey(uint *const player= NULL);
  string getOutputJsonKey(int index, uint *const player= NULL);
};

#endif
