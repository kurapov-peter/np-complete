#pragma once

class CNF {
  unsigned _dim = 0;

 public:
  unsigned GetDim() { return _dim; };
  static CNF GenerateCNFOfSizeN(unsigned n) { return CNF(/*...*/); };
};