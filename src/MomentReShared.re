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
  let momentWithComponents: list(int) => Moment.t;
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
  [@mel.send] external humanize: t => string = "humanize";
  [@mel.send] external milliseconds: t => int = "milliseconds";
  [@mel.send] external asMilliseconds: t => float = "asMilliseconds";
  [@mel.send] external seconds: t => int = "seconds";
  [@mel.send] external asSeconds: t => float = "asSeconds";
  [@mel.send] external minutes: t => int = "minutes";
  [@mel.send] external asMinutes: t => float = "asMinutes";
  [@mel.send] external hours: t => int = "hours";
  [@mel.send] external asHours: t => float = "asHours";
  [@mel.send] external days: t => int = "days";
  [@mel.send] external asDays: t => float = "asDays";
  [@mel.send] external weeks: t => int = "weeks";
  [@mel.send] external asWeeks: t => float = "asWeeks";
  [@mel.send] external months: t => int = "months";
  [@mel.send] external asMonths: t => float = "asMonths";
  [@mel.send] external years: t => int = "years";
  [@mel.send] external asYears: t => float = "asYears";
  [@mel.send] external toJSON: t => string = "toJSON";
  [@mel.send] external toISOString: t => string = "toISOString";
  [@mel.send.pipe: t]
  external asUnitOfTime:
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
    ] =>
    float =
    "as";
};

module Moment = {
  type t;
  [@mel.send.pipe: t] external clone: t = "clone";
  [@mel.send] external mutableAdd: (t, Duration.t) => unit = "add";
  let add = (~duration, moment) => {
    let clone = clone(moment);
    mutableAdd(clone, duration);
    clone;
  };
  [@mel.send] external mutableSubtract: (t, Duration.t) => unit = "subtract";
  let subtract = (~duration, moment) => {
    let clone = clone(moment);
    mutableSubtract(clone, duration);
    clone;
  };
  [@mel.send]
  external mutableStartOf:
    (
      t,
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
      t,
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
  [@mel.send] external mutableSetMillisecond: (t, int) => unit = "millisecond";
  let setMillisecond = (millisecond, moment) => {
    let clone = clone(moment);
    mutableSetMillisecond(clone, millisecond);
    clone;
  };
  [@mel.send] external mutableSetSecond: (t, int) => unit = "second";
  let setSecond = (second, moment) => {
    let clone = clone(moment);
    mutableSetSecond(clone, second);
    clone;
  };
  [@mel.send] external mutableSetMinute: (t, int) => unit = "minute";
  let setMinute = (minute, moment) => {
    let clone = clone(moment);
    mutableSetMinute(clone, minute);
    clone;
  };
  [@mel.send] external mutableSetHour: (t, int) => unit = "hour";
  let setHour = (hour, moment) => {
    let clone = clone(moment);
    mutableSetHour(clone, hour);
    clone;
  };
  [@mel.send] external mutableSetDate: (t, int) => unit = "date";
  let setDate = (date, moment) => {
    let clone = clone(moment);
    mutableSetDate(clone, date);
    clone;
  };
  [@mel.send] external mutableSetDay: (t, int) => unit = "day";
  let setDay = (day, moment) => {
    let clone = clone(moment);
    mutableSetDay(clone, day);
    clone;
  };
  [@mel.send] external mutableSetWeekday: (t, int) => unit = "weekday";
  let setWeekday = (weekday, moment) => {
    let clone = clone(moment);
    mutableSetWeekday(clone, weekday);
    clone;
  };
  [@mel.send] external mutableSetIsoWeekday: (t, int) => unit = "isoWeekday";
  let setIsoWeekday = (isoWeekday, moment) => {
    let clone = clone(moment);
    mutableSetIsoWeekday(clone, isoWeekday);
    clone;
  };
  [@mel.send] external mutableSetDayOfYear: (t, int) => unit = "dayOfYear";
  let setDayOfYear = (dayOfYear, moment) => {
    let clone = clone(moment);
    mutableSetDayOfYear(clone, dayOfYear);
    clone;
  };
  [@mel.send] external mutableSetWeek: (t, int) => unit = "week";
  let setWeek = (week, moment) => {
    let clone = clone(moment);
    mutableSetWeek(clone, week);
    clone;
  };
  [@mel.send] external mutableSetIsoWeek: (t, int) => unit = "isoWeek";
  let setIsoWeek = (isoWeek, moment) => {
    let clone = clone(moment);
    mutableSetIsoWeek(clone, isoWeek);
    clone;
  };
  [@mel.send] external mutableSetQuarter: (t, int) => unit = "quarter";
  let setQuarter = (quarter, moment) => {
    let clone = clone(moment);
    mutableSetQuarter(clone, quarter);
    clone;
  };
  [@mel.send] external mutableSetWeekYear: (t, int) => unit = "weekYear";
  let setWeekYear = (weekYear, moment) => {
    let clone = clone(moment);
    mutableSetWeekYear(clone, weekYear);
    clone;
  };
  [@mel.send] external mutableSetIsoWeekYear: (t, int) => unit = "isoWeekYear";
  let setIsoWeekYear = (isoWeekYear, moment) => {
    let clone = clone(moment);
    mutableSetWeekYear(clone, isoWeekYear);
    clone;
  };
  [@mel.send] external mutableSetMonth: (t, int) => unit = "month";
  let setMonth = (month, moment) => {
    let clone = clone(moment);
    mutableSetMonth(clone, month);
    clone;
  };
  [@mel.send] external mutableSetYear: (t, int) => unit = "year";
  let setYear = (year, moment) => {
    let clone = clone(moment);
    mutableSetYear(clone, year);
    clone;
  };
  [@mel.send.pipe: t]
  external get:
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
    ] =>
    int =
    "get";
  [@mel.send.pipe: t] external millisecond: int = "millisecond";
  [@mel.send.pipe: t] external second: int = "second";
  [@mel.send.pipe: t] external minute: int = "minute";
  [@mel.send.pipe: t] external hour: int = "hour";
  [@mel.send.pipe: t] external day: int = "day";
  [@mel.send.pipe: t] external date: int = "date";
  [@mel.send.pipe: t] external week: int = "week";
  [@mel.send.pipe: t] external month: int = "month";
  [@mel.send.pipe: t] external year: int = "year";
  [@mel.send.pipe: t] external weekday: int = "weekday";
  [@mel.send] external isValid: t => bool = "isValid";
  [@mel.send] external isBefore: (t, t) => bool = "isBefore";
  [@mel.send] external isAfter: (t, t) => bool = "isAfter";
  [@mel.send]
  external isAfterWithGranularity:
    (
      t,
      t,
      [ | `year | `month | `week | `isoWeek | `day | `hour | `minute | `second]
    ) =>
    bool =
    "isAfter";
  [@mel.send]
  external isSameOrBeforeWithGranularity:
    (
      t,
      t,
      [ | `year | `month | `week | `isoWeek | `day | `hour | `minute | `second]
    ) =>
    bool =
    "isSameOrBefore";
  [@mel.send] external isSame: (t, t) => bool = "isSame";
  [@mel.send]
  external isSameWithGranularity: (t, t, [ | `year | `month | `day]) => bool =
    "isSame";
  [@mel.send] external isSameOrBefore: (t, t) => bool = "isSameOrBefore";
  [@mel.send] external isSameOrAfter: (t, t) => bool = "isSameOrAfter";
  [@mel.send] external isBetween: (t, t, t) => bool = "isBetween";
  [@mel.send] external isDST: t => bool = "isDST";
  [@mel.send] external isLeapYear: t => bool = "isLeapYear";
  /* display */
  [@mel.send.pipe: t] external format: string => string = "format";
  [@mel.send.pipe: t] external defaultFormat: string = "format";
  [@mel.send.pipe: t] external utc: string => t = "utc";
  [@mel.send.pipe: t] external defaultUtc: t = "utc";
  [@mel.send.pipe: t] external mutableLocale: string => unit = "locale";
  let locale = (locale, moment) => {
    let clone = clone(moment);
    mutableLocale(locale, clone);
    clone;
  };
  [@mel.send]
  external fromNow: (t, ~withoutSuffix: option(bool)) => string = "fromNow";
  [@mel.send]
  external fromMoment: (t, ~other: t, ~format: option(string)) => string =
    "from";
  [@mel.send]
  external toNow: (t, ~withoutSuffix: option(bool)) => string = "toNow";
  [@mel.send]
  external toMoment: (t, ~other: t, ~format: string) => string = "to";
  [@mel.send] external valueOf: t => float = "valueOf";
  [@mel.send] external daysInMonth: t => int = "daysInMonth";
  [@mel.send] external toJSON: t => Js.null(string) = "toJSON";
  let toJSON = moment => toJSON(moment) |> Js.Null.toOption;
  [@mel.send] external toDate: t => Js.Date.t = "toDate";
  [@mel.send] external toUnix: t => int = "unix";
  [@mel.send.pipe: t]
  external toISOString: (~keepOffset: bool=?) => string = "toISOString";
};

[@mel.send]
external diff:
  (
    Moment.t,
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
    Moment.t,
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
