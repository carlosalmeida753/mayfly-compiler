// $Id: MUL.h,v 1.9 2013/02/09 19:00:34 david Exp $ -*- c++ -*-
#ifndef __CDK8_NODE_EXPRESSION_MUL_H__
#define __CDK8_NODE_EXPRESSION_MUL_H__

#include <cdk/nodes/expressions/BinaryExpression.h>
#include "SemanticProcessor.h"

namespace cdk {
  namespace node {
    namespace expression {

      /**
       * Class for describing the multiplication operator
       */
      class MUL: public BinaryExpression {
      public:
        /**
         * @param lineno source code line number for this nodes
         * @param left first operand
         * @param right second operand
         */
        inline MUL(int lineno, Expression *left, Expression *right) :
          BinaryExpression(lineno, left, right) {
        }

        /**
         * @return the name of the node's class
         */
        const char *name() const {
          return "MUL";
        }

        /**
         * @param sp semantic processor visitor
         * @param level syntactic tree level
         */
        virtual void accept(SemanticProcessor *sp, int level) {
          sp->processMUL(this, level);
        }

      };

    } // expression
  } // node
} // cdk

#endif

// $Log: MUL.h,v $
// Revision 1.9  2013/02/09 19:00:34  david
// First CDK8 commit. Major code simplification.
// Starting C++11 implementation.
//
// Revision 1.8  2012/04/10 19:01:05  david
// Removed initialization-dependent static members in factories.
// Handling of ProgramNodes is now better encapsulated by visitors (not done
// by evaluators, as before). Major cleanup (comments).
//
// Revision 1.7  2012/03/06 15:07:45  david
// Added subtype to ExpressionType. This allows for more expressiveness in
// type description.
//
