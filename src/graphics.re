open ReasonJs;

type cullmode =
    | Clockwise
    | CounterClockwise
    | None;

module PipeLine = {
    type pipe = {
        mutable cullMode: cullmode,
    };
};

module Graphics = {
    type color = {r: float, g: float, b: float, a: float};

    /* Begin is overloaded */
    let begin_ = fun gl => {

        GL.(enable gl GL._BLEND);
        GL.(blendFunc gl GL._SRC_ALPHA GL._ONE_MINUS_SRC_ALPHA);

/*
        if (renderTarget == null) {
            SystemImpl.gl.bindFramebuffer(GL.FRAMEBUFFER, null);
            SystemImpl.gl.viewport(0, 0, System.windowWidth(), System.windowHeight());
        } else {
            ..
        }
*/

    };


    let clear = fun (gl, c : color) => {
        GL.(clearColor gl c.r c.g c.b c.a);
        GL.(clear gl GL._COLOR_BUFFER_BIT);
    };

    let setCullMode = fun (gl, cullMode : cullmode) => {
        switch cullMode {
            | None => GL.(disable gl GL._CULL_FACE);
            | Clockwise => {
                GL.(enable gl GL._CULL_FACE);
                GL.(cullFace gl GL._BACK);
            }
            | CounterClockwise => {
                GL.(enable gl GL._CULL_FACE);
                GL.(cullFace gl GL._FRONT);
            }
        }
    };

    let setPipeline = fun (gl, pipe : PipeLine.pipe) => {
        setCullMode(gl, pipe.cullMode);
        /*
        setDepthMode(pipe.depthWrite, pipe.depthMode);
        setStencilParameters(pipe.stencilMode, pipe.stencilBothPass, pipe.stencilDepthFail, pipe.stencilFail, pipe.stencilReferenceValue, pipe.stencilReadMask, pipe.stencilWriteMask);
        setBlendingMode(pipe.blendSource, pipe.blendDestination, pipe.blendOperation, pipe.alphaBlendSource, pipe.alphaBlendDestination, pipe.alphaBlendOperation);
        pipe.set();
        */
    };

};