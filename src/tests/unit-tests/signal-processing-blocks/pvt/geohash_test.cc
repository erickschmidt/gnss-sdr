/*!
 * \file geohash_test.cc
 * \brief Implements Unit Tests for the Geohash class.
 * \author Carles Fernandez-Prades, 2023. cfernandez(at)cttc.es
 *
 * -----------------------------------------------------------------------------
 *
 * GNSS-SDR is a Global Navigation Satellite System software-defined receiver.
 * This file is part of GNSS-SDR.
 *
 * Copyright (C) 2010-2023  (see AUTHORS file for a list of contributors)
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * -----------------------------------------------------------------------------
 */

#include "geohash.h"

TEST(Geohash_Test, Encode)
{
    Geohash gh = Geohash();
    std::string geohash;
    EXPECT_NO_THROW(geohash = gh.encode(52.205, 0.119, 7));
    EXPECT_EQ(0, geohash.compare("u120fxw"));
    EXPECT_THROW(gh.encode(52.205, 0.119, 0), std::invalid_argument);
}

TEST(Geohash_Test, Decode)
{
    Geohash gh = Geohash();
    auto latlon = gh.decode("sp36v1zk0e2g");
    EXPECT_NEAR(41.274966141209006, latlon[0], 1e-8);
    EXPECT_NEAR(1.9875180535018444, latlon[1], 1e-8);
    EXPECT_THROW(gh.decode(""), std::runtime_error);
}

TEST(Geohash_Test, Precision)
{
    Geohash gh = Geohash();
    std::string hash;
    EXPECT_NO_THROW(hash = gh.encode(52.205, 0.119, 6));
    EXPECT_EQ(0, hash.compare("u120fx"));
    EXPECT_NO_THROW(hash = gh.encode(52.205, 0.119, 5));
    EXPECT_EQ(0, hash.compare("u120f"));
}