module Duration = MomentReShared.Duration;

module Moment = MomentReShared.Moment;

let diff = MomentReShared.diff;

let diffWithPrecision = MomentReShared.diffWithPrecision;

[@mel.module "moment"] [@mel.scope "default"]
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

[@mel.module "moment"] [@mel.scope "default"]
external durationMillis: float => Duration.t = "duration";

[@mel.module "moment"] [@mel.scope "default"]
external durationFormat: string => Duration.t = "duration";

/* parse */
[@mel.module "moment"] external momentNow: unit => Moment.t = "default";

[@mel.module "moment"]
external momentDefaultFormat: string => Moment.t = "default";

[@mel.module "moment"]
external momentWithFormat: (string, string) => Moment.t = "default";

[@mel.module "moment"]
external momentWithDate: Js.Date.t => Moment.t = "default";

[@mel.module "moment"]
external momentWithFormats: (string, array(string)) => Moment.t = "default";

[@mel.module "moment"]
external momentWithTimestampMS: float => Moment.t = "default";

[@mel.module "moment"]
external momentWithComponents: array(int) => Moment.t = "default";

[@mel.module "moment"] [@mel.scope "default"]
external momentUtcWithFormats: (string, array(string)) => Moment.t = "utc";

[@mel.module "moment"] [@mel.scope "default"]
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
