//    <SciMax, a Scilab toolbox to connect Maxima.>
//    Copyright (C) <2009>  <Calixte DENIZET>

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.

//   You should have received a copy of the GNU General Public License
//   along with this program.  If not, see <http://www.gnu.org/licenses/>.


//   Contact : Calixte DENIZET <calixte.denizet@ac-rennes.fr>

#include "stack-c.h"
#include "maxsci1.h"

extern int maxevalf (int, char *);
extern int creerSym (int, char *, char **, int, int, char);

int
sci_maxevalf (fname)
     char *fname;
{
  static int l, m, n;
  int pos;

  if (max_is_ok == 0)
    {
      Scierror (9999, "Maxima has not been started : use maxinit\n");
      return -1;
    }
  if (quest_mode == 1)
    {
      Scierror (9999,"You must answer to the question !\n");
      return -1;
    }

  CheckLhs (1, 1) ;
  
  GetRhsVar (1, SD, &m, &n, &l);
  
  n = maxevalf (1, cstk (l));
  if (n == -1 || n == 1)
    {
      creerSym (1, "nil", NULL, 3, 1, 'M');
      LhsVar (1) = 1;
      return -1;
    }
    
  LhsVar (1) = 1; 
  return 0;
}


