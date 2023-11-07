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

[@mel.module "moment"]
external duration:
  (
    float,
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
  Duration.t =
  "duration";

[@mel.module "moment"]
external durationMillis: float => Duration.t = "duration";

[@mel.module "moment"]
external durationFormat: string => Duration.t = "duration";

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

/* parse */
[@mel.module "moment"] external momentNow: unit => Moment.t = "default";

[@mel.module "moment"] external momentDefaultFormat: string => Moment.t = "default";

[@mel.module "moment"]
external momentWithFormat: (string, string) => Moment.t = "default";

[@mel.module "moment"] external momentWithDate: Js.Date.t => Moment.t = "default";

[@mel.module "moment"]
external momentWithFormats: (string, array(string)) => Moment.t = "default";

[@mel.module "moment"] external momentWithTimestampMS: float => Moment.t = "default";

[@mel.module "moment"] external momentWithComponents: list(int) => Moment.t = "default";

[@mel.module "moment"]
external momentUtcWithFormats: (string, array(string)) => Moment.t = "utc";

[@mel.module "moment"]
external momentUtcDefaultFormat: string => Moment.t = "utc";

let momentWithUnix = (timestamp: int) =>
  momentWithTimestampMS(float_of_int(timestamp) *. 1000.0);

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

let momentUtc = (~format=?, value) =>
  switch (format) {
  | Some(f) => momentUtcWithFormats(value, f)
  | None => momentUtcDefaultFormat(value)
  };

let moment = (~format=?, value) =>
  switch (format) {
  | Some(f) => momentWithFormats(value, f)
  | None => momentDefaultFormat(value)
  };
