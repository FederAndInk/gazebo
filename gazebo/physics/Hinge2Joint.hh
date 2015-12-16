/*
 * Copyright (C) 2012-2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _GAZEBO_PHYSICS_HINGE2JOINT_HH_
#define _GAZEBO_PHYSICS_HINGE2JOINT_HH_

#include <sdf/sdf.hh>
#include <ignition/math/Vector3.hh>

#include "gazebo/physics/Joint.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace physics
  {
    /// \addtogroup gazebo_physics
    /// \{

    /// \class Hinge2Joint Hinge2Joint.hh physics/physics.hh
    /// \brief A two axis hinge joint
    template<class T>
    class GZ_PHYSICS_VISIBLE Hinge2Joint : public T
    {
      /// \brief Constructor.
      /// \param[in] _parent Parent link.
      public: explicit Hinge2Joint(BasePtr _parent) : T(_parent)
      {
        this->AddType(Base::HINGE2_JOINT);
      }

      /// \brief Destructor.
      public: virtual ~Hinge2Joint()
      {
      }

      // Documentation inherited.
      public: virtual unsigned int AngleCount() const
      {
        return 2;
      }

      /// \brief Load the joint.
      /// \param[in] _sdf SDF values to load from.
      public: virtual void Load(sdf::ElementPtr _sdf)
      {
        T::Load(_sdf);

        this->SetAxis(0,
            _sdf->GetElement("axis")->Get<ignition::math::Vector3d>("xyz"));

        this->SetAxis(1,
            _sdf->GetElement("axis2")->Get<ignition::math::Vector3d>("xyz"));
      }
    };
    /// \}
  }
}
#endif
