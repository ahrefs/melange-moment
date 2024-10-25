module Duration = MomentReShared.Duration;

module Moment = MomentReShared.Moment;

let diff = MomentReShared.diff;

let diffWithPrecision = MomentReShared.diffWithPrecision;

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

/* parse */
[@mel.module] external momentNow: unit => Moment.t = "moment";

[@mel.module] external momentDefaultFormat: string => Moment.t = "moment";

[@mel.module]
external momentWithFormat: (string, string) => Moment.t = "moment";

[@mel.module] external momentWithDate: Js.Date.t => Moment.t = "moment";

[@mel.module]
external momentWithFormats: (string, array(string)) => Moment.t = "moment";

[@mel.module] external momentWithTimestampMS: float => Moment.t = "moment";

[@mel.module]
external momentWithComponents: array(int) => Moment.t = "moment";

[@mel.module "moment"]
external momentUtcWithFormats: (string, array(string)) => Moment.t = "utc";

[@mel.module "moment"]
external momentUtcDefaultFormat: string => Moment.t = "utc";

let momentWithUnix = (timestamp: int) =>
  momentWithTimestampMS(float_of_int(timestamp) *. 1000.0);

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
