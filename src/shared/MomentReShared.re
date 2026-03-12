module type MomentRe = {
  module Duration: {
    type t;
    let humanize: t => string;
    let milliseconds: t => int;
    let asMilliseconds: t => float;
    let seconds: t => int;
    let asSeconds: t => float;
    let minutes: t => int;
    let asMinutes: t => float;
    let hours: t => int;
    let asHours: t => float;
    let days: t => int;
    let asDays: t => float;
    let weeks: t => int;
    let asWeeks: t => float;
    let months: t => int;
    let asMonths: t => float;
    let years: t => int;
    let asYears: t => float;
    let toJSON: t => string;
    let toISOString: t => string;
    let asUnitOfTime:
      (
        [
          | `days
          | `hours
          | `milliseconds
          | `minutes
          | `months
          | `quarters
          | `seconds
          | `weeks
          | `years
        ],
        t
      ) =>
      float;
  };
  let duration:
    (
      float,
      [
        | `days
        | `hours
        | `milliseconds
        | `minutes
        | `months
        | `quarters
        | `seconds
        | `weeks
        | `years
      ]
    ) =>
    Duration.t;
  let durationMillis: float => Duration.t;
  let durationFormat: string => Duration.t;
  module Moment: {
    type t;
    let clone: t => t;
    let mutableAdd: (t, Duration.t) => unit;
    let add: (~duration: Duration.t, t) => t;
    let mutableSubtract: (t, Duration.t) => unit;
    let subtract: (~duration: Duration.t, t) => t;
    let mutableStartOf:
      (
        t,
        [
          | `day
          | `hour
          | `isoWeek
          | `millisecond
          | `minute
          | `month
          | `quarter
          | `second
          | `week
          | `year
        ]
      ) =>
      unit;
    let startOf:
      (
        [
          | `day
          | `hour
          | `isoWeek
          | `millisecond
          | `minute
          | `month
          | `quarter
          | `second
          | `week
          | `year
        ],
        t
      ) =>
      t;
    let mutableEndOf:
      (
        t,
        [
          | `day
          | `hour
          | `isoWeek
          | `millisecond
          | `minute
          | `month
          | `quarter
          | `second
          | `week
          | `year
        ]
      ) =>
      unit;
    let endOf:
      (
        [
          | `day
          | `hour
          | `isoWeek
          | `millisecond
          | `minute
          | `month
          | `quarter
          | `second
          | `week
          | `year
        ],
        t
      ) =>
      t;
    let mutableSetMillisecond: (t, int) => unit;
    let setMillisecond: (int, t) => t;
    let mutableSetSecond: (t, int) => unit;
    let setSecond: (int, t) => t;
    let mutableSetMinute: (t, int) => unit;
    let setMinute: (int, t) => t;
    let mutableSetHour: (t, int) => unit;
    let setHour: (int, t) => t;
    let mutableSetDate: (t, int) => unit;
    let setDate: (int, t) => t;
    let mutableSetDay: (t, int) => unit;
    let setDay: (int, t) => t;
    let mutableSetWeekday: (t, int) => unit;
    let setWeekday: (int, t) => t;
    let mutableSetIsoWeekday: (t, int) => unit;
    let setIsoWeekday: (int, t) => t;
    let mutableSetDayOfYear: (t, int) => unit;
    let setDayOfYear: (int, t) => t;
    let mutableSetWeek: (t, int) => unit;
    let setWeek: (int, t) => t;
    let mutableSetIsoWeek: (t, int) => unit;
    let setIsoWeek: (int, t) => t;
    let mutableSetQuarter: (t, int) => unit;
    let setQuarter: (int, t) => t;
    let mutableSetWeekYear: (t, int) => unit;
    let setWeekYear: (int, t) => t;
    let mutableSetIsoWeekYear: (t, int) => unit;
    let setIsoWeekYear: (int, t) => t;
    let mutableSetMonth: (t, int) => unit;
    let setMonth: (int, t) => t;
    let mutableSetYear: (t, int) => unit;
    let setYear: (int, t) => t;
    let get:
      (
        [
          | `date
          | `day
          | `hour
          | `millisecond
          | `minute
          | `month
          | `quarter
          | `second
          | `week
          | `year
        ],
        t
      ) =>
      int;
    let millisecond: t => int;
    let second: t => int;
    let minute: t => int;
    let hour: t => int;
    let day: t => int;
    let date: t => int;
    let week: t => int;
    let month: t => int;
    let year: t => int;
    let weekday: t => int;
    let isValid: t => bool;
    let isBefore: (t, t) => bool;
    let isAfter: (t, t) => bool;
    let isAfterWithGranularity:
      (
        t,
        t,
        [
          | `day
          | `hour
          | `isoWeek
          | `minute
          | `month
          | `second
          | `week
          | `year
        ]
      ) =>
      bool;
    let isSameOrBeforeWithGranularity:
      (
        t,
        t,
        [
          | `day
          | `hour
          | `isoWeek
          | `minute
          | `month
          | `second
          | `week
          | `year
        ]
      ) =>
      bool;
    let isSame: (t, t) => bool;
    let isSameWithGranularity: (t, t, [ | `day | `month | `year]) => bool;
    let isSameOrBefore: (t, t) => bool;
    let isSameOrAfter: (t, t) => bool;
    let isBetween: (t, t, t) => bool;
    let isDST: t => bool;
    let isLeapYear: t => bool;
    let format: (string, t) => string;
    let defaultFormat: t => string;
    let utc: (string, t) => t;
    let defaultUtc: t => t;
    let mutableLocale: (string, t) => unit;
    let locale: (string, t) => t;
    let fromNow: (t, ~withoutSuffix: option(bool)) => string;
    let fromMoment: (t, ~other: t, ~format: option(string)) => string;
    let toNow: (t, ~withoutSuffix: option(bool)) => string;
    let toMoment: (t, ~other: t, ~format: string) => string;
    let valueOf: t => float;
    let daysInMonth: t => int;
    let toJSON: t => option(string);
    let toDate: t => Js.Date.t;
    let toUnix: t => int;
    let toISOString: (~keepOffset: bool=?, t) => string;
  };
  let momentNow: unit => Moment.t;
  let momentDefaultFormat: string => Moment.t;
  let momentWithFormat: (string, string) => Moment.t;
  let momentWithDate: Js.Date.t => Moment.t;
  let momentWithFormats: (string, array(string)) => Moment.t;
  let momentWithTimestampMS: float => Moment.t;
  let momentWithComponents: array(int) => Moment.t;
  let momentUtcWithFormats: (string, array(string)) => Moment.t;
  let momentUtcDefaultFormat: string => Moment.t;
  let momentWithUnix: int => Moment.t;
  let diff:
    (
      Moment.t,
      Moment.t,
      [
        | `days
        | `hours
        | `milliseconds
        | `minutes
        | `months
        | `quarters
        | `seconds
        | `weeks
        | `years
      ]
    ) =>
    float;
  let diffWithPrecision:
    (
      Moment.t,
      Moment.t,
      [
        | `days
        | `hours
        | `milliseconds
        | `minutes
        | `months
        | `quarters
        | `seconds
        | `weeks
        | `years
      ],
      bool
    ) =>
    float;
  let momentUtc: (~format: array(string)=?, string) => Moment.t;
  let moment: (~format: array(string)=?, string) => Moment.t;
};

/* duration */
module Duration = {
  type t;
  [@mel.send] external humanize: ([@mel.this] t) => string = "humanize";
  [@mel.send] external milliseconds: ([@mel.this] t) => int = "milliseconds";
  [@mel.send] external asMilliseconds: ([@mel.this] t) => float = "asMilliseconds";
  [@mel.send] external seconds: ([@mel.this] t) => int = "seconds";
  [@mel.send] external asSeconds: ([@mel.this] t) => float = "asSeconds";
  [@mel.send] external minutes: ([@mel.this] t) => int = "minutes";
  [@mel.send] external asMinutes: ([@mel.this] t) => float = "asMinutes";
  [@mel.send] external hours: ([@mel.this] t) => int = "hours";
  [@mel.send] external asHours: ([@mel.this] t) => float = "asHours";
  [@mel.send] external days: ([@mel.this] t) => int = "days";
  [@mel.send] external asDays: ([@mel.this] t) => float = "asDays";
  [@mel.send] external weeks: ([@mel.this] t) => int = "weeks";
  [@mel.send] external asWeeks: ([@mel.this] t) => float = "asWeeks";
  [@mel.send] external months: ([@mel.this] t) => int = "months";
  [@mel.send] external asMonths: ([@mel.this] t) => float = "asMonths";
  [@mel.send] external years: ([@mel.this] t) => int = "years";
  [@mel.send] external asYears: ([@mel.this] t) => float = "asYears";
  [@mel.send] external toJSON: ([@mel.this] t) => string = "toJSON";
  [@mel.send] external toISOString: ([@mel.this] t) => string = "toISOString";
  [@mel.send]
  external asUnitOfTime:
    (
      [
        | `years
        | `quarters
        | `months
        | `weeks
        | `days
        | `hours
        | `minutes
        | `seconds
        | `milliseconds
      ],
      [@mel.this] t
    ) =>
    float =
    "as";
};

module Moment = {
  type t;
  [@mel.send] external clone: ([@mel.this] t) => t = "clone";
  [@mel.send] external mutableAdd: ([@mel.this] t, Duration.t) => unit = "add";
  let add = (~duration, moment) => {
    let clone = clone(moment);
    mutableAdd(clone, duration);
    clone;
  };
  [@mel.send] external mutableSubtract: ([@mel.this] t, Duration.t) => unit = "subtract";
  let subtract = (~duration, moment) => {
    let clone = clone(moment);
    mutableSubtract(clone, duration);
    clone;
  };
  [@mel.send]
  external mutableStartOf:
    (
      [@mel.this] t,
      [
        | `year
        | `quarter
        | `month
        | `week
        | `isoWeek
        | `day
        | `hour
        | `minute
        | `second
        | `millisecond
      ]
    ) =>
    unit =
    "startOf";
  let startOf = (timeUnit, moment) => {
    let clone = clone(moment);
    mutableStartOf(clone, timeUnit);
    clone;
  };
  [@mel.send]
  external mutableEndOf:
    (
      [@mel.this] t,
      [
        | `year
        | `quarter
        | `month
        | `week
        | `isoWeek
        | `day
        | `hour
        | `minute
        | `second
        | `millisecond
      ]
    ) =>
    unit =
    "endOf";
  let endOf = (timeUnit, moment) => {
    let clone = clone(moment);
    mutableEndOf(clone, timeUnit);
    clone;
  };
  [@mel.send] external mutableSetMillisecond: ([@mel.this] t, int) => unit = "millisecond";
  let setMillisecond = (millisecond, moment) => {
    let clone = clone(moment);
    mutableSetMillisecond(clone, millisecond);
    clone;
  };
  [@mel.send] external mutableSetSecond: ([@mel.this] t, int) => unit = "second";
  let setSecond = (second, moment) => {
    let clone = clone(moment);
    mutableSetSecond(clone, second);
    clone;
  };
  [@mel.send] external mutableSetMinute: ([@mel.this] t, int) => unit = "minute";
  let setMinute = (minute, moment) => {
    let clone = clone(moment);
    mutableSetMinute(clone, minute);
    clone;
  };
  [@mel.send] external mutableSetHour: ([@mel.this] t, int) => unit = "hour";
  let setHour = (hour, moment) => {
    let clone = clone(moment);
    mutableSetHour(clone, hour);
    clone;
  };
  [@mel.send] external mutableSetDate: ([@mel.this] t, int) => unit = "date";
  let setDate = (date, moment) => {
    let clone = clone(moment);
    mutableSetDate(clone, date);
    clone;
  };
  [@mel.send] external mutableSetDay: ([@mel.this] t, int) => unit = "day";
  let setDay = (day, moment) => {
    let clone = clone(moment);
    mutableSetDay(clone, day);
    clone;
  };
  [@mel.send] external mutableSetWeekday: ([@mel.this] t, int) => unit = "weekday";
  let setWeekday = (weekday, moment) => {
    let clone = clone(moment);
    mutableSetWeekday(clone, weekday);
    clone;
  };
  [@mel.send] external mutableSetIsoWeekday: ([@mel.this] t, int) => unit = "isoWeekday";
  let setIsoWeekday = (isoWeekday, moment) => {
    let clone = clone(moment);
    mutableSetIsoWeekday(clone, isoWeekday);
    clone;
  };
  [@mel.send] external mutableSetDayOfYear: ([@mel.this] t, int) => unit = "dayOfYear";
  let setDayOfYear = (dayOfYear, moment) => {
    let clone = clone(moment);
    mutableSetDayOfYear(clone, dayOfYear);
    clone;
  };
  [@mel.send] external mutableSetWeek: ([@mel.this] t, int) => unit = "week";
  let setWeek = (week, moment) => {
    let clone = clone(moment);
    mutableSetWeek(clone, week);
    clone;
  };
  [@mel.send] external mutableSetIsoWeek: ([@mel.this] t, int) => unit = "isoWeek";
  let setIsoWeek = (isoWeek, moment) => {
    let clone = clone(moment);
    mutableSetIsoWeek(clone, isoWeek);
    clone;
  };
  [@mel.send] external mutableSetQuarter: ([@mel.this] t, int) => unit = "quarter";
  let setQuarter = (quarter, moment) => {
    let clone = clone(moment);
    mutableSetQuarter(clone, quarter);
    clone;
  };
  [@mel.send] external mutableSetWeekYear: ([@mel.this] t, int) => unit = "weekYear";
  let setWeekYear = (weekYear, moment) => {
    let clone = clone(moment);
    mutableSetWeekYear(clone, weekYear);
    clone;
  };
  [@mel.send] external mutableSetIsoWeekYear: ([@mel.this] t, int) => unit = "isoWeekYear";
  let setIsoWeekYear = (isoWeekYear, moment) => {
    let clone = clone(moment);
    mutableSetWeekYear(clone, isoWeekYear);
    clone;
  };
  [@mel.send] external mutableSetMonth: ([@mel.this] t, int) => unit = "month";
  let setMonth = (month, moment) => {
    let clone = clone(moment);
    mutableSetMonth(clone, month);
    clone;
  };
  [@mel.send] external mutableSetYear: ([@mel.this] t, int) => unit = "year";
  let setYear = (year, moment) => {
    let clone = clone(moment);
    mutableSetYear(clone, year);
    clone;
  };
  [@mel.send]
  external get:
    (
      [
        | `year
        | `quarter
        | `month
        | `week
        | `day
        | `date
        | `hour
        | `minute
        | `second
        | `millisecond
      ],
      [@mel.this] t
    ) =>
    int =
    "get";
  [@mel.send] external millisecond: ([@mel.this] t) => int = "millisecond";
  [@mel.send] external second: ([@mel.this] t) => int = "second";
  [@mel.send] external minute: ([@mel.this] t) => int = "minute";
  [@mel.send] external hour: ([@mel.this] t) => int = "hour";
  [@mel.send] external day: ([@mel.this] t) => int = "day";
  [@mel.send] external date: ([@mel.this] t) => int = "date";
  [@mel.send] external week: ([@mel.this] t) => int = "week";
  [@mel.send] external month: ([@mel.this] t) => int = "month";
  [@mel.send] external year: ([@mel.this] t) => int = "year";
  [@mel.send] external weekday: ([@mel.this] t) => int = "weekday";
  [@mel.send] external isValid: ([@mel.this] t) => bool = "isValid";
  [@mel.send] external isBefore: ([@mel.this] t, t) => bool = "isBefore";
  [@mel.send] external isAfter: ([@mel.this] t, t) => bool = "isAfter";
  [@mel.send]
  external isAfterWithGranularity:
    (
      [@mel.this] t,
      t,
      [ | `year | `month | `week | `isoWeek | `day | `hour | `minute | `second]
    ) =>
    bool =
    "isAfter";
  [@mel.send]
  external isSameOrBeforeWithGranularity:
    (
      [@mel.this] t,
      t,
      [ | `year | `month | `week | `isoWeek | `day | `hour | `minute | `second]
    ) =>
    bool =
    "isSameOrBefore";
  [@mel.send] external isSame: ([@mel.this] t, t) => bool = "isSame";
  [@mel.send]
  external isSameWithGranularity: ([@mel.this] t, t, [ | `year | `month | `day]) => bool =
    "isSame";
  [@mel.send] external isSameOrBefore: ([@mel.this] t, t) => bool = "isSameOrBefore";
  [@mel.send] external isSameOrAfter: ([@mel.this] t, t) => bool = "isSameOrAfter";
  [@mel.send] external isBetween: ([@mel.this] t, t, t) => bool = "isBetween";
  [@mel.send] external isDST: ([@mel.this] t) => bool = "isDST";
  [@mel.send] external isLeapYear: ([@mel.this] t) => bool = "isLeapYear";
  /* display */
  [@mel.send] external format: (string, [@mel.this] t) => string = "format";
  [@mel.send] external defaultFormat: ([@mel.this] t) => string = "format";
  [@mel.send] external utc: (string, [@mel.this] t) => t = "utc";
  [@mel.send] external defaultUtc: ([@mel.this] t) => t = "utc";
  [@mel.send] external mutableLocale: (string, [@mel.this] t) => unit = "locale";
  let locale = (locale, moment) => {
    let clone = clone(moment);
    mutableLocale(locale, clone);
    clone;
  };
  [@mel.send]
  external fromNow: ([@mel.this] t, ~withoutSuffix: option(bool)) => string = "fromNow";
  [@mel.send]
  external fromMoment: ([@mel.this] t, ~other: t, ~format: option(string)) => string =
    "from";
  [@mel.send]
  external toNow: ([@mel.this] t, ~withoutSuffix: option(bool)) => string = "toNow";
  [@mel.send]
  external toMoment: ([@mel.this] t, ~other: t, ~format: string) => string = "to";
  [@mel.send] external valueOf: ([@mel.this] t) => float = "valueOf";
  [@mel.send] external daysInMonth: ([@mel.this] t) => int = "daysInMonth";
  [@mel.send] external toJSON: ([@mel.this] t) => Js.null(string) = "toJSON";
  let toJSON = moment => toJSON(moment) |> Js.Null.toOption;
  [@mel.send] external toDate: ([@mel.this] t) => Js.Date.t = "toDate";
  [@mel.send] external toUnix: ([@mel.this] t) => int = "unix";
  [@mel.send]
  external toISOString: (~keepOffset: bool=?, [@mel.this] t) => string = "toISOString";
};

[@mel.send]
external diff:
  (
    [@mel.this] Moment.t,
    Moment.t,
    [
      | `years
      | `quarters
      | `months
      | `weeks
      | `days
      | `hours
      | `minutes
      | `seconds
      | `milliseconds
    ]
  ) =>
  float =
  "diff";

[@mel.send]
external diffWithPrecision:
  (
    [@mel.this] Moment.t,
    Moment.t,
    [
      | `years
      | `quarters
      | `months
      | `weeks
      | `days
      | `hours
      | `minutes
      | `seconds
      | `milliseconds
    ],
    bool
  ) =>
  float =
  "diff";
