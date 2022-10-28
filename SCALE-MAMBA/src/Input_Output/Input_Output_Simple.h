/*
Copyright (c) 2017, The University of Bristol, Senate House, Tyndall Avenue, Bristol, BS8 1TH, United Kingdom.
Copyright (c) 2021, COSIC-KU Leuven, Kasteelpark Arenberg 10, bus 2452, B-3001 Leuven-Heverlee, Belgium.

All rights reserved
*/
#ifndef _InputOutputSimple
#define _InputOutputSimple

/* A simple IO class which just uses standard
 * input/output to communicate values
 *
 * Whereas share values are input/output using
 * a steam, with either human or non-human form
 */

#include "Input_Output_Base.h"

#include <fstream>
using namespace std;

class Input_Output_Simple : public Input_Output_Base
{
  // Total number of lines
  uint *nLines;

  // Number of input columns
  uint numColumnsIn;

  // Current row
  string sRow;
  // Current column index
  uint iColumn;

  istream *inpf;
  ostream *outf;

  // Store for multiple output values
  vector<int> *vOutput;
  ifstream fin;
  ofstream fout;
  ifstream fsharein;
  ofstream fshareout;

  bool human; // Only affects share output
protected:
  uint count_lines(const string &filePath);
  bool read_in(string &line);

public:
  // Constructor
  Input_Output_Simple();

  // Destructor
  ~Input_Output_Simple();

  // Initialize streams
  void init(int playerIndex, int playerCount, string outPath, string shareInPath, string shareOutPath, bool human_type);
  void init(int playerIndex, int playerCount, string inPath, string outPath, string shareInPath, string shareOutPath, bool human_type);

  virtual long open_channel(unsigned int channel);
  virtual void close_channel(unsigned int channel);

  virtual gfp private_input_gfp(unsigned int channel);
  virtual void private_output_gfp(const gfp &output, unsigned int channel);

  virtual void public_output_gfp(const gfp &output, unsigned int channel);
  virtual gfp public_input_gfp(unsigned int channel);

  virtual void public_output_int(const long output, unsigned int channel);
  virtual long public_input_int(unsigned int channel);

  virtual void output_share(const Share &S, unsigned int channel);
  virtual Share input_share(unsigned int channel);

  virtual void trigger(Schedule &schedule);

  virtual void debug_output(const stringstream &ss);

  virtual void crash(unsigned int PC, unsigned int thread_num);
};

#endif
