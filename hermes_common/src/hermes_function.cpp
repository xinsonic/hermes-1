// This file is part of Hermes2D.
//
// Hermes2D is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Hermes2D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Hermes2D.  If not, see <http://www.gnu.org/licenses/>.

#include "hermes_function.h"

namespace Hermes
{
  template<typename Scalar>
  bool Hermes1DFunction<Scalar>::is_constant() const
  {
    return is_const;
  };

  template<typename Scalar>
  bool Hermes2DFunction<Scalar>::is_constant() const
  {
    return is_const;
  };

  template<typename Scalar>
  bool Hermes3DFunction<Scalar>::is_constant() const
  {
    return is_const;
  };

  template<typename Scalar>
  Hermes1DFunction<Scalar>::Hermes1DFunction()
  {
    this->is_const = true;
  };

  template<typename Scalar>
  Hermes1DFunction<Scalar>::Hermes1DFunction(Scalar value)
  {
    this->is_const = true;
    this->const_value = value;
  };

  template<>
  double Hermes1DFunction<double>::value(double x) const
  {
    if(this->is_const)
      return const_value;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes1DFunction<double>::value");
      return 0.0;
    }
  };
  template<>
  std::complex<double> Hermes1DFunction<std::complex<double> >::value(std::complex<double> x) const
  {
    if(this->is_const)
      return const_value;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes1DFunction<std::complex<double> >::value");
      return std::complex<double>(0.0, 0.0);
    }
  };

  template<typename Scalar>
  Ord Hermes1DFunction<Scalar>::value(Ord x) const
  {
    if(this->is_const)
      return Ord(0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes1DFunction<Scalar>::value");
      return Ord(99);
    }
  };

  template<>
  double Hermes1DFunction<double>::derivative(double x) const
  {
    if(this->is_const)
      return 0.0;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes1DFunction<double>::derivative");
      return 0.0;
    }
  };
  template<>
  std::complex<double> Hermes1DFunction<std::complex<double> >::derivative(std::complex<double> x) const
  {
    if(this->is_const)
      return std::complex<double>(0.0, 0.0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes1DFunction<std::complex<double> >::derivative");
      return std::complex<double>(0.0, 0.0);
    }
  };

  template<typename Scalar>
  Ord Hermes1DFunction<Scalar>::derivative(Ord x) const
  {
    if(this->is_const)
      return Ord(0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes1DFunction<Scalar>::derivative");
      return Ord(99);
    }
  };

  template<typename Scalar>
  Hermes2DFunction<Scalar>::Hermes2DFunction()
  {
    this->is_const = true;
  };

  template<typename Scalar>
  Hermes2DFunction<Scalar>::Hermes2DFunction(Scalar value)
  {
    this->is_const = true;
    this->const_value = value;
  };

  template<>
  double Hermes2DFunction<double>::value(double x, double y) const
  {
    if(this->is_const)
      return const_value;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes2DFunction<double>::value");
      return 0.0;
    }
  };

  template<>
  std::complex<double> Hermes2DFunction<std::complex<double> >::value(std::complex<double> x, std::complex<double> y) const
  {
    if(this->is_const)
      return const_value;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes2DFunction<std::complex<double> >::value");
      return std::complex<double>(0.0, 0.0);
    }
  };

  template<typename Scalar>
  Ord Hermes2DFunction<Scalar>::value(Ord x, Ord y) const
  {
    if(this->is_const)
      return Ord(0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes2DFunction<Scalar>::value");
      return Ord(99);
    }
  };

  template<>
  double Hermes2DFunction<double>::derivativeX(double x, double y) const
  {
    if(this->is_const)
      return 0.0;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes2DFunction<double>::derivativeX");
      return 0.0;
    }
  };
  template<>
  std::complex<double> Hermes2DFunction<std::complex<double> >::derivativeX(std::complex<double> x, std::complex<double> y) const
  {
    if(this->is_const)
      return std::complex<double>(0.0, 0.0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes2DFunction<std::complex<double> >::derivativeX");
      return std::complex<double>(0.0, 0.0);
    }
  };

  template<typename Scalar>
  Ord Hermes2DFunction<Scalar>::derivativeX(Ord x, Ord y) const
  {
    if(this->is_const)
      return Ord(0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes2DFunction<Scalar>::derivativeX");
      return Ord(99);
    }
  };

  template<>
  double Hermes2DFunction<double>::derivativeY(double x, double y) const
  {
    if(this->is_const)
      return 0.0;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes2DFunction<double>::derivativeY");
      return 0.0;
    }
  };
  template<>
  std::complex<double> Hermes2DFunction<std::complex<double> >::derivativeY(std::complex<double> x, std::complex<double> y) const
  {
    if(this->is_const)
      return std::complex<double>(0.0, 0.0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes2DFunction<std::complex<double> >::derivativeY");
      return std::complex<double>(0.0, 0.0);
    }
  };

  template<typename Scalar>
  Ord Hermes2DFunction<Scalar>::derivativeY(Ord x, Ord y) const
  {
    if(this->is_const)
      return Ord(0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes2DFunction<Scalar>::derivativeY");
      return Ord(99);
    }
  };

  template<typename Scalar>
  Hermes3DFunction<Scalar>::Hermes3DFunction()
  {
    this->is_const = true;
  };

  template<typename Scalar>
  Hermes3DFunction<Scalar>::Hermes3DFunction(Scalar value)
  {
    this->is_const = true;
    this->const_value = value;
  };

  template<>
  double Hermes3DFunction<double>::value(double x, double y, double z) const
  {
    if(this->is_const)
      return 0.0;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<double>::value");
      return 0.0;
    }
  };
  template<>
  std::complex<double> Hermes3DFunction<std::complex<double> >::value(std::complex<double> x, std::complex<double> y, std::complex<double> z) const
  {
    if(this->is_const)
      return std::complex<double>(0.0, 0.0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<std::complex<double> >::value");
      return std::complex<double>(0.0, 0.0);
    }
  };

  template<typename Scalar>
  Ord Hermes3DFunction<Scalar>::value(Ord x, Ord y, Ord z) const
  {
    if(this->is_const)
      return Ord(0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<Scalar>::value");
      return Ord(99);
    }
  };

  template<>
  double Hermes3DFunction<double>::derivativeX(double x, double y, double z) const
  {
    if(this->is_const)
      return 0.0;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<double>::derivativeX");
      return 0.0;
    }
  };
  template<>
  std::complex<double> Hermes3DFunction<std::complex<double> >::derivativeX(std::complex<double> x, std::complex<double> y, std::complex<double> z) const
  {
    if(this->is_const)
      return std::complex<double>(0.0, 0.0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<std::complex<double> >::derivativeX");
      return std::complex<double>(0.0, 0.0);
    }
  };

  template<typename Scalar>
  Ord Hermes3DFunction<Scalar>::derivativeX(Ord x, Ord y, Ord z) const
  {
    if(this->is_const)
      return Ord(0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<Scalar>::derivativeX");
      return Ord(99);
    }
  };

  template<>
  double Hermes3DFunction<double>::derivativeY(double x, double y, double z) const
  {
    if(this->is_const)
      return 0.0;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<double>::derivativeY");
      return 0.0;
    }
  };
  template<>
  std::complex<double> Hermes3DFunction<std::complex<double> >::derivativeY(std::complex<double> x, std::complex<double> y, std::complex<double> z) const
  {
    if(this->is_const)
      return std::complex<double>(0.0, 0.0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<std::complex<double> >::derivativeY");
      return std::complex<double>(0.0, 0.0);
    }
  };

  template<typename Scalar>
  Ord Hermes3DFunction<Scalar>::derivativeY(Ord x, Ord y, Ord z) const
  {
    if(this->is_const)
      return Ord(0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<Scalar>::derivativeY");
      return Ord(99);
    }
  };

  template<>
  double Hermes3DFunction<double>::derivativeZ(double x, double y, double z) const
  {
    if(this->is_const)
      return 0.0;
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<double>::derivativeZ");
      return 0.0;
    }
  };
  template<>
  std::complex<double> Hermes3DFunction<std::complex<double> >::derivativeZ(std::complex<double> x, std::complex<double> y, std::complex<double> z) const
  {
    if(this->is_const)
      return std::complex<double>(0.0, 0.0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<std::complex<double> >::derivativeZ");
      return std::complex<double>(0.0, 0.0);
    }
  };

  template<typename Scalar>
  Ord Hermes3DFunction<Scalar>::derivativeZ(Ord x, Ord y, Ord z) const
  {
    if(this->is_const)
      return Ord(0);
    else
    {
      throw Hermes::Exceptions::FunctionNotOverridenException("Hermes3DFunction<Scalar>::derivativeZ");
      return Ord(99);
    }
  };

  template class HERMES_API Hermes1DFunction<double>;
  template class HERMES_API Hermes1DFunction<std::complex<double> >;
  template class HERMES_API Hermes2DFunction<double>;
  template class HERMES_API Hermes2DFunction<std::complex<double> >;
  template class HERMES_API Hermes3DFunction<double>;
  template class HERMES_API Hermes3DFunction<std::complex<double> >;
}