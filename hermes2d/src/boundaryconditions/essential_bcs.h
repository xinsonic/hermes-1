// This file is part of Hermes3D
//
// Copyright (c) 2009 hp-FEM group at the University of Nevada, Reno (UNR).
// Email: hpfem-group@unr.edu, home page: http://hpfem.org/.
//
// Hermes3D is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
//
// Hermes3D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Hermes3D; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef __HERMES_COMMON_BOUNDARYCONDITIONS_H
#define __HERMES_COMMON_BOUNDARYCONDITIONS_H

#include "vector.h"
#include "map"

/// Abstract class representing Essential boundary condition of the form u|_{\Gamma_Essential} = u_Essential.
class HERMES_API EssentialBC
{
public:
  /// Default constructor.
  EssentialBC(Hermes::vector<std::string> markers);

  /// Virtual destructor.
  virtual ~EssentialBC();

  /// Types of description of boundary values, either a function (callback), or a constant.
  enum EssentialBCValueType {
    BC_FUNCTION,
    BC_VALUE
  };

  /// Pure virtual function giving info whether u_Essential is a constant or a function.
  virtual EssentialBCValueType get_value_type() const = 0;

  /// Represents a function prescribed on the boundary.
  virtual scalar function(double x, double y) const;

  /// Special case of a constant function.
  scalar value;

  /// Sets the current time for time-dependent boundary conditions.
  void set_current_time(double time);
  double get_current_time() const;

protected:
  /// Current time.
  double current_time;
  
  // Markers.
  Hermes::vector<std::string> markers;

  // Friend class.
  friend class EssentialBCS;
};

/// Class representing Essential boundary condition of the form u|_{\Gamma_Essential} = u_Essential given by value.
class HERMES_API EssentialBCConstant : public EssentialBC {
public:
  /// Constructors.
  EssentialBCConstant(Hermes::vector<std::string> markers, scalar value);
  EssentialBCConstant(std::string marker, scalar value);

  /// Function giving info that u_Essential is a constant.
  inline EssentialBCValueType get_value_type() const { return EssentialBC::BC_VALUE; }
};

/// Class encapsulating all boundary conditions of one problem.
/// Using the class BoundaryCondition and its descendants.
class HERMES_API EssentialBCS {
public:
  /// Default constructor.
  EssentialBCS();

  /// Constructor with all boundary conditions of a problem.
  EssentialBCS(Hermes::vector<EssentialBC *> essential_bcs);
  EssentialBCS(EssentialBC * boundary_condition);

  /// Default destructor.
  ~EssentialBCS();

  /// Initializes the class, fills the structures.
  void add_boundary_conditions(Hermes::vector<EssentialBC *> essential_bcs);
  void add_boundary_condition(EssentialBC * essential_bc);

  /// Public iterators for the private data structures.
  Hermes::vector<EssentialBC *>::const_iterator iterator;
  Hermes::vector<EssentialBC *>::const_iterator begin() const;
  Hermes::vector<EssentialBC *>::const_iterator end() const;
  
  EssentialBC* get_boundary_condition(std::string marker);

  /// Sets the current time for time-dependent boundary conditions.
  void set_current_time(double time);

private:
  /// All boundary conditions together.
  Hermes::vector<EssentialBC *> all;

  /// Boundary markers cache
  std::map<std::string, EssentialBC *> markers;

  /// Create boundary markers cache for assembling
  void create_marker_cache();
};

#endif

