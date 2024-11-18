/*
 * Copyright 2024 The OpenRobotic Beginner Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <stdlib.h>

namespace openbot {
namespace control {

/**
 * @brief An iterator implementing Bresenham Ray-Tracing.
 */
class LineIterator
{
public:
  /**
   * @brief A constructor for LineIterator
   * @param x0 Starting x
   * @param y0 Starting y
   * @param x1 Ending x
   * @param y1 Ending y
   */
  LineIterator(int x0, int y0, int x1, int y1)
  : x0_(x0),
    y0_(y0),
    x1_(x1),
    y1_(y1),
    x_(x0),    // X and Y start of at first endpoint.
    y_(y0),
    deltax_(abs(x1 - x0)),
    deltay_(abs(y1 - y0)),
    curpixel_(0)
  {
    if (x1_ >= x0_) {                // The x-values are increasing
      xinc1_ = 1;
      xinc2_ = 1;
    } else {                      // The x-values are decreasing
      xinc1_ = -1;
      xinc2_ = -1;
    }

    if (y1_ >= y0_) {               // The y-values are increasing
      yinc1_ = 1;
      yinc2_ = 1;
    } else {                      // The y-values are decreasing
      yinc1_ = -1;
      yinc2_ = -1;
    }

    if (deltax_ >= deltay_) {        // There is at least one x-value for every y-value
      xinc1_ = 0;                  // Don't change the x when numerator >= denominator
      yinc2_ = 0;                  // Don't change the y for every iteration
      den_ = deltax_;
      num_ = deltax_ / 2;
      numadd_ = deltay_;
      numpixels_ = deltax_;         // There are more x-values than y-values
    } else {                      // There is at least one y-value for every x-value
      xinc2_ = 0;                  // Don't change the x for every iteration
      yinc1_ = 0;                  // Don't change the y when numerator >= denominator
      den_ = deltay_;
      num_ = deltay_ / 2;
      numadd_ = deltax_;
      numpixels_ = deltay_;         // There are more y-values than x-values
    }
  }

  /**
   * @brief If the iterator is valid
   * @return bool If valid
   */
  bool isValid() const
  {
    return curpixel_ <= numpixels_;
  }

  /**
   * @brief Advance iteration along the line
   */
  void advance()
  {
    num_ += numadd_;              // Increase the numerator by the top of the fraction
    if (num_ >= den_) {           // Check if numerator >= denominator
      num_ -= den_;               // Calculate the new numerator value
      x_ += xinc1_;               // Change the x as appropriate
      y_ += yinc1_;               // Change the y as appropriate
    }
    x_ += xinc2_;                 // Change the x as appropriate
    y_ += yinc2_;                 // Change the y as appropriate

    curpixel_++;
  }

  /**
   * @brief Get current X value
   * @return X
   */
  int getX() const
  {
    return x_;
  }

  /**
   * @brief Get current Y value
   * @return Y
   */
  int getY() const
  {
    return y_;
  }

  /**
   * @brief Get initial X value
   * @return X
   */
  int getX0() const
  {
    return x0_;
  }

  /**
   * @brief Get initial Y value
   * @return Y
   */
  int getY0() const
  {
    return y0_;
  }

  /**
   * @brief Get terminal X value
   * @return X
   */
  int getX1() const
  {
    return x1_;
  }

  /**
   * @brief Get terminal Y value
   * @return Y
   */
  int getY1() const
  {
    return y1_;
  }

private:
  int x0_;  ///< X coordinate of first end point.
  int y0_;  ///< Y coordinate of first end point.
  int x1_;  ///< X coordinate of second end point.
  int y1_;  ///< Y coordinate of second end point.

  int x_;  ///< X coordinate of current point.
  int y_;  ///< Y coordinate of current point.

  int deltax_;  ///< Difference between Xs of endpoints.
  int deltay_;  ///< Difference between Ys of endpoints.

  int curpixel_;  ///< index of current point in line loop.

  int xinc1_, xinc2_, yinc1_, yinc2_;
  int den_, num_, numadd_, numpixels_;
};

}  // namespace control
}  // namespace openbot

