cfg = coder.config('exe','ecoder',true);
cfg.HardwareImplementation.ProdEqTarget = false;
cfg.TargetLang = 'C++';
cfg.GenCodeOnly = true;
cfg.GenerateExampleMain = 'DoNotGenerate';
cfg.GenerateMakefile = false;
cfg.GenerateReport = true;
cfg.MaxIdLength = 1024;
cfg.ReportPotentialDifferences = false;
cfg.TargetLangStandard = 'C++11 (ISO)';
cfg.RuntimeChecks = true;

ARGS = cell(1,1);
ARGS{1} = cell(1,1);
ARGS{1}{1} = coder.typeof(0.0);
ARGS{1}{2} = coder.typeof(0.0);
ARGS{1}{3} = coder.typeof('X',[1 Inf],[0 1]);

codegen -config cfg psdSpectrum -args ARGS{1}

