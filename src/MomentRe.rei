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
      [ | `day | `hour | `isoWeek | `minute | `month | `second | `week | `year]
    ) =>
    bool;
  let isSameOrBeforeWithGranularity:
    (
      t,
      t,
      [ | `day | `hour | `isoWeek | `minute | `month | `second | `week | `year]
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
