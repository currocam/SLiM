//
//  QtSLiM_Plot.h
//  SLiM
//
//  Created by Ben Haller on 1/30/2024.
//  Copyright (c) 2024 Philipp Messer.  All rights reserved.
//	A product of the Messer Lab, http://messerlab.org/slim/
//

//	This file is part of SLiM.
//
//	SLiM is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//
//	SLiM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License along with SLiM.  If not, see <http://www.gnu.org/licenses/>.

#ifndef QTSLIM_PLOT_H
#define QTSLIM_PLOT_H


#include <vector>
#include <string>
#include <map>

#include "eidos_value.h"
#include "slim_globals.h"

class QtSLiMGraphView_CustomPlot;


extern EidosClass *gSLiM_Plot_Class;


class Plot : public EidosDictionaryUnretained
{
    //	This class has its copy constructor and assignment operator disabled, to prevent accidental copying.
    
private:
	typedef EidosDictionaryUnretained super;

public:
    
    std::string title_;                                     // the title as given to createPlot()
	QtSLiMGraphView_CustomPlot *plotview_;                  // We have a reference to the QtSLiMGraphView_CustomPlot that displays us
	
	Plot(const Plot&) = delete;                             // no copying
	Plot& operator=(const Plot&) = delete;                  // no copying
	Plot(void) = delete;                                    // no null construction
    Plot(const std::string &title, QtSLiMGraphView_CustomPlot *p_plotview);
	virtual ~Plot(void) override;
	
	
	//
	// Eidos support
	//
	virtual const EidosClass *Class(void) const override;
    virtual void Print(std::ostream &p_ostream) const override;
	
	virtual EidosValue_SP GetProperty(EidosGlobalStringID p_property_id) override;
	virtual void SetProperty(EidosGlobalStringID p_property_id, const EidosValue &p_value) override;
	
	virtual EidosValue_SP ExecuteInstanceMethod(EidosGlobalStringID p_method_id, const std::vector<EidosValue_SP> &p_arguments, EidosInterpreter &p_interpreter) override;
    EidosValue_SP ExecuteMethod_addLegend(EidosGlobalStringID p_method_id, const std::vector<EidosValue_SP> &p_arguments, EidosInterpreter &p_interpreter);
    EidosValue_SP ExecuteMethod_legendLineEntry(EidosGlobalStringID p_method_id, const std::vector<EidosValue_SP> &p_arguments, EidosInterpreter &p_interpreter);
    EidosValue_SP ExecuteMethod_legendPointEntry(EidosGlobalStringID p_method_id, const std::vector<EidosValue_SP> &p_arguments, EidosInterpreter &p_interpreter);
    EidosValue_SP ExecuteMethod_legendSwatchEntry(EidosGlobalStringID p_method_id, const std::vector<EidosValue_SP> &p_arguments, EidosInterpreter &p_interpreter);
    EidosValue_SP ExecuteMethod_lines(EidosGlobalStringID p_method_id, const std::vector<EidosValue_SP> &p_arguments, EidosInterpreter &p_interpreter);
    EidosValue_SP ExecuteMethod_points(EidosGlobalStringID p_method_id, const std::vector<EidosValue_SP> &p_arguments, EidosInterpreter &p_interpreter);
    EidosValue_SP ExecuteMethod_text(EidosGlobalStringID p_method_id, const std::vector<EidosValue_SP> &p_arguments, EidosInterpreter &p_interpreter);
    EidosValue_SP ExecuteMethod_write(EidosGlobalStringID p_method_id, const std::vector<EidosValue_SP> &p_arguments, EidosInterpreter &p_interpreter);
};

class Plot_Class : public EidosDictionaryUnretained_Class
{
private:
	typedef EidosDictionaryUnretained_Class super;

public:
	Plot_Class(const Plot_Class &p_original) = delete;	// no copy-construct
	Plot_Class& operator=(const Plot_Class&) = delete;	// no copying
	inline Plot_Class(const std::string &p_class_name, EidosClass *p_superclass) : super(p_class_name, p_superclass) { }
	
	virtual const std::vector<EidosPropertySignature_CSP> *Properties(void) const override;
	virtual const std::vector<EidosMethodSignature_CSP> *Methods(void) const override;
};


#endif // QTSLIM_PLOT_H


































