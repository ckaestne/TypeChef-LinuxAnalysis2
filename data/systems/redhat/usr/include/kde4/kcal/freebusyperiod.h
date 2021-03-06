/*
  This file is part of the kcal library.

  Copyright (c) 2001-2003 Cornelius Schumacher <schumacher@kde.org>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Library General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Library General Public License for more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; see the file COPYING.LIB.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.
*/
/**
  @file
  This file is part of the API for handling calendar data and
  defines the Period class.

  @brief
  Represents a period of time.

  @author Cornelius Schumacher \<schumacher@kde.org\>
*/

#ifndef KCAL_FREEBUSYPERIOD_H
#define KCAL_FREEBUSYPERIOD_H

#include "kcal_export.h"
#include "duration.h"
#include "period.h"

#include <kdatetime.h>
#include <QtCore/QList>

namespace KCal {

/**
  The period can be defined by either a start time and an end time or
  by a start time and a duration.
*/
class KCAL_EXPORT FreeBusyPeriod : public Period
{
  public:
   /**
      List of periods.
    */
    typedef QList<FreeBusyPeriod> List;

    /**
      Constructs a period without a duration.
    */
    FreeBusyPeriod();

    /**
      Constructs a period from @p start to @p end.

      @param start the time the period begins.
      @param end the time the period ends.
    */
    FreeBusyPeriod( const KDateTime &start, const KDateTime &end );

    /**
      Constructs a period from @p start and lasting @p duration.

      @param start the time when the period starts.
      @param duration how long the period lasts.
    */
    FreeBusyPeriod( const KDateTime &start, const Duration &duration );

    /**
      Constructs a period by copying another period object

      @param period the period to copy
     */

    FreeBusyPeriod( const FreeBusyPeriod &period );

    /**
      Constructs a period by copying another period object

      @param period the period to copy
     */

    FreeBusyPeriod( const Period &period );

    /**
      Destroys a period.
    */
    ~FreeBusyPeriod();

    /**
      Sets this period equal to the @p other one.

      @param other is the other period to compare.
    */
    FreeBusyPeriod &operator=( const FreeBusyPeriod &other );

    QString summary() const;
    void setSummary( const QString &summary );
    QString location() const;
    void setLocation( const QString &location );

  private:
    //@cond PRIVATE
    class Private;
    Private *const d;
    //@endcond
};

}

#endif
