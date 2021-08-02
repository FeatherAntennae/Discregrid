
#pragma once

#include <Eigen/Core>
#include <array>

namespace Discregrid
{

    enum class NearestEntity
    {
        VN0,
        VN1,
        VN2,
        EN0,
        EN1,
        EN2,
        FN
    };

    float point_triangle_sqdistance(Eigen::Vector3f const &point,
                                    std::array<Eigen::Vector3f const *, 3> const &triangle,
                                    Eigen::Vector3f *nearest_point = nullptr,
                                    NearestEntity *ne = nullptr);

}
