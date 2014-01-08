/*****************************************************************************
 *   GATB : Genome Assembly Tool Box                                         *
 *   Authors: [R.Chikhi, G.Rizk, E.Drezen]                                   *
 *   Based on Minia, Authors: [R.Chikhi, G.Rizk], CeCILL license             *
 *   Copyright (c) INRIA, CeCILL license, 2013                               *
 *****************************************************************************/

/** \file ICell.hpp
 *  \date 01/03/2013
 *  \author edrezen
 *  \brief Node
 */

#ifndef _GATB_CORE_STORAGE_ICELL_HPP_
#define _GATB_CORE_STORAGE_ICELL_HPP_

/********************************************************************************/

#include <gatb/system/api/ISmartPointer.hpp>
#include <string>

/********************************************************************************/
namespace gatb      {
namespace core      {
namespace tools     {
namespace storage   {
/********************************************************************************/

/** \brief Interface for a cell
 */
class ICell : public virtual system::ISmartPointer
{
public:

    /** Destructor. */
    virtual ~ICell() {}

    /** Get the parent node (if any).
     * \return the parent node. */
    virtual ICell* getParent () const = 0;

    /** Return the identifier of the node.
     * \return the id of the node. */
    virtual const std::string& getId () const = 0;

    /** Return the full identifier (like a path "x.y.z")
     * \return the full identifier. */
    virtual std::string getFullId (char sep='.') const = 0;

    /** Physically remove the node. */
    virtual void remove () = 0;

    /** Get the root of the given cell
     * \param[in] cell : the cell we want to get the root
     * \return the root of the given cell  */
    static ICell* getRoot (ICell* cell)
    {
        ICell* loop=0;  for (loop=cell ; loop && loop->getParent() != 0;  loop=loop->getParent())  {}
        return loop;
    }
};

/********************************************************************************/
} } } } /* end of namespaces. */
/********************************************************************************/

#endif /* _GATB_CORE_STORAGE_ICELL_HPP_ */